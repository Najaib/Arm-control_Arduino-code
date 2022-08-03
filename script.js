var SpeechRecognition = window.webkitSpeechRecognition

var recognition = new SpeechRecognition()

var textbox = $("#textbox")

var instructions = $("#instructions")

var content = ''

recognition.continuous = true

recognition.lang='ar';

recognition.onstart = function () {
    instructions.text("Voive Recognition is on")
}
recognition.onspeechend = function () {
    instructions.text("No Activity")
}

recognition.onerror = function (){
    instructions.text("Try Again")
}

recognition.onresult= function (event){
    var current = event.resultIndex;

    var transcript= event.results[current][0].transcript

    content += transcript

    textbox.val(content)
}

$("#start-btn").click(function(event) {
if (content.length){
    content += ''
}
recognition.start()
})
$('#pause-record-btn').click(function(event) {
    recognition.stop();
    instructions.text('Voice recognition paused');
});

textbox.on('input', function (){
    content = $(this).val()
})