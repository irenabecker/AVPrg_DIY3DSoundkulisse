
var objects=[{
                "shape":"",
                "color":"",
                "posX":0,
                "posY":0
            }]

function initialize(){
	let midi = null;  // global MIDIAccess object
	let midiInputs = [];
	function onMIDISuccess( midiAccess ) {
	  console.log( "MIDI ready!" );
	  midi = midiAccess;  // store in the global (in real usage, would probably keep in an object instance)
		listInputsAndOutputs(midi);
	}

	function onMIDIFailure(msg) {
	  console.log( "Failed to get MIDI access - " + msg );
	}

	navigator.requestMIDIAccess().then( onMIDISuccess, onMIDIFailure );
	function listInputsAndOutputs( midiAccess ) {
		const inputPortSelector = document.getElementById('inputportselector');
		for (let input of midiAccess.inputs.values()) {
		  var opt = document.createElement("option");
		  opt.text = input.name;
		  document.getElementById("inputportselector").add(opt);
		  midiInputs.push(input);
		  console.log( "Input port [type:'" + input.type + "'] id:'" + input.id +
			"' manufacturer:'" + input.manufacturer + "' name:'" + input.name +
			"' version:'" + input.version + "'" );
		}
		if (midiInputs.length > 1){
			inputPortSelector.addEventListener('click', ()=>{
				selectMidiInput(inputPortSelector.selectedIndex);
			});
		}
		selectMidiInput(inputPortSelector.selectedIndex);
	}

	
	function selectMidiInput(index){
		const selectedIndex = document.getElementById('inputportselector').selectedIndex;
		const midiInput = midiInputs[selectedIndex];
		midiInput.onmidimessage = MIDIMessageEventHandler;
		return midiInput;
	}
	function MIDIMessageEventHandler(event) {
        //get channel = Color
        var channel=event.data[0]&0x0f;
        var color="";
        switch(channel)
            {
                case 0x00: color="RED";break;
                case 0x01: color="GREEN";break;
                case 0x02: color="BLUE";break;
                case 0x03: color="CALIBRATION_COLOR";break;
            }        
        
      // Mask off the lower nibble (MIDI channel, which we don't care about)
        //switch through calle method = shape
        //0x90 = noteOn = RECTANGLE
        //0x80 = noteOff = CIRCLE
        //0xB0 = controlChange = TRIANGLE
      switch (event.data[0] & 0xf0) {
        case 0x90:
			noteOn(color,event.data[1], event.data[2]);
			break;
        case 0x80:
			noteOff(color,event.data[1], event.data[2]);
			break;
		case 0xB0:
			controlChange(color,event.data[1], event.data[2]);
			break; 
        case 0xC0:
            resetObjects(); 
            break;
      }
    }
	function noteOn(color,posX,posY){
        objects[objects.length]={ "shape":"RECTANGLE",
                                    "color":color,
                                    "posX":posX,
                                    "posY":posY};
        /*objects.append({ "shape":"RECTANGLE",
                        "color":color,
                        "posX":posX,
                        "posY":posY});*/
        //console.log("RECTANGLE, "+color+", PosX: "+posX+", PosY: "+posY);
		//console.log(`note on: note=${noteNumber}, velocity = ${velocity}`);
	}
	function noteOff(color, posX, posY){
        objects[objects.length]={ "shape":"CIRCLE",
                                    "color":color,
                                    "posX":posX,
                                    "posY":posY};
        /*objects.append({ "shape":"CIRCLE",
                        "color":color,
                        "posX":posX,
                        "posY":posY});*/
       //console.log("RECTANGLE, "+color+", PosX: "+posX+", PosY: "+posY);
		//console.log(`note off: note=${noteNumber}`);
	}
	function controlChange(color, posX, posY){
        
        objects[objects.length]={ "shape":"TRIANGLE",
                                    "color":color,
                                    "posX":posX,
                                    "posY":posY};
        /*objects.append({ "shape":"TRIANGLE",
                        "color":color,
                        "posX":posX,
                        "posY":posY});*/
        //console.log("RECTANGLE, "+color+", PosX: "+posX+", PosY: "+posY);
		//console.log(`control change: controller = ${controller}, value = ${value}`);
	}
    function resetObjects()
    {
        console.clear();
        for(var i=0;i<objects.length;i++)
            {
                console.log("Shape:, "+objects[i].shape+" Color: "+objects[i].color+", PosX: "+objects[i].posX+", PosY: "+objects[i].posY);
            }
        objects=[{
                "shape":"",
                "color":"",
                "posX":0,
                "posY":0
                }];
    }
}