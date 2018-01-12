
var midiJSONObjects=[]

function initialize(){
	let midi = null;  // global MIDIAccess object
	let midiInputs = [];
    
	function onMIDISuccess( midiAccess ) {
	  console.log( "MIDI ready!" );
	  midi = midiAccess;  // store in the global (in real usage, would probably keep in an object instance)
        let inputs = midi.inputs.values();
		//listInputsAndOutputs(midi);
      //Loop through all Midi-Inputs
        for (let input = inputs.next(); input && !input.done; input = inputs.next()) 
            {
                input.value.onmidimessage = MIDIMessageEventHandler;
            }
	}

	function onMIDIFailure(msg) {
	  console.log( "Failed to get MIDI access - " + msg );
	}

	navigator.requestMIDIAccess().then( onMIDISuccess, onMIDIFailure );
    /*
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
    */
	/*
	function selectMidiInput(index){
		const selectedIndex = document.getElementById('inputportselector').selectedIndex;
		const midiInput = midiInputs[selectedIndex];
		midiInput.onmidimessage = MIDIMessageEventHandler;
		return midiInput;
	}*/
    
	function MIDIMessageEventHandler(event) {
        //get channel = Color
        console.log("event data[0]:"+event.data[0]);
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
        let shape;
      switch (event.data[0] & 0xf0) {
        case 0x90:
			shape = 'RECTANGLE';
			break;
        case 0x80:
              shape = 'CIRCLE';
			break;
		case 0xB0:
              shape = 'TRIANGLE';
			break; 
        case 0xC0:
            resetJSONObjects(); 
            break;
      }
        if (shape.length != 0)
            createJSONObject(shape,color,event.data[1], event.data[2]);
    }
    
	function createJSONObject(shape,color,posX,posY){
        midiJSONObjects.push('{' +
            '"shape":'+shape+',' +
            '"color":'+color+',' +
            '"posX":'+posX+','+
            '"posY":'+posY+
        '}');
        console.log("RECTANGLE, "+color+", PosX: "+posX+", PosY: "+posY);
	}
    /*
	function noteOff(color, posX, posY){
        midiJSONObjects.push({ 
            "shape":"CIRCLE",
            "color":color,
            "posX":posX,
            "posY":posY
        });
        
       console.log("CIRCLE, "+color+", PosX: "+posX+", PosY: "+posY);
	}
    
	function controlChange(color, posX, posY){
        
        midiJSONObjects.push('{
            "shape":"TRIANGLE",
            "color":color,
            "posX":posX,
            "posY":posY
        }');
                             
        console.log("TRIANGLE, "+color+", PosX: "+posX+", PosY: "+posY);
	}
    */
    function resetJSONObjects()
    {
        console.log(midiJSONObjects.length + ", objects get emtpyed now");
        
        //zur anzeige weiterleiten
        
        midiJSONObjects=[];
    }
}