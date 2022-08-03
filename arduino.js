let isConnectted = false;
      let port;
      let writer;
      var target_id;
      const enc = new TextEncoder();

      async function onChangespeech() {
        if (!isConnectted) {
          alert("connect to the usb in order to use this.");
          return; }
       
        try {
          const comlist = content;
          const comSplit = comlist.split(" ")
          const command = comSplit.slice(-1);
          const computerT = `${command}@`;
          await writer.write(enc.encode(computerT));
        } catch (e) {
          console.log(e);
        }
      }
    
    async function onConnectUsb() {
      try {
        const requestOptions = {
          // Filter on devices with the Arduino USB vendor ID.
          filters: [{ usbVendorId: 0x2341 }],
        };

        // Request an Arduino from the user.
        port = await navigator.serial.requestPort(requestOptions);
        await port.open({ baudRate: 115200 });
        writer = port.writable.getWriter();
        isConnectted = true;
      } catch (e) {
        console.log("eror", e);
      }
    }