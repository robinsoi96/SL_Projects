function turnOff(){
    document.getElementById("lightBulb").src="image/off.png";
    document.getElementById("displayText").innerHTML="Status: Bulb is now <mark><strong>OFF</strong></mark>";
}

function turnOn(){
    document.getElementById("lightBulb").src="image/on.png";
    document.getElementById("displayText").innerHTML="Status: Bulb is now <mark><strong>ON</strong></mark>";
}