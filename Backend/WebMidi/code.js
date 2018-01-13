var midiJSONObjects=[]

function initialize(){
	let midi = null;  // global MIDIAccess object
	let midiInputs = [];
    
	function onMIDISuccess( midiAccess ) {
	  console.log( "MIDI ready!" );
	  midi = midiAccess;  // store in the global (in real usage, would probably keep in an object instance)
        let inputs = midi.inputs.values();
      //Loop through all Midi-Inputs
        for (let input = inputs.next(); input && !input.done; input = inputs.next()) 
            {
                input.value.onmidimessage = MIDIMessageEventHandler;
            }
	}

	function onMIDIFailure(msg) {
	  console.log( "Failed to get MIDI access - " + msg );
	}

	navigator.requestMIDIAccess({sysex:true}).then( onMIDISuccess, onMIDIFailure );
    
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
        console.log("Shape: "+shape+ " color: "+color+", PosX: "+posX+", PosY: "+posY);
	}
    
    function resetJSONObjects()
    {
        console.log(midiJSONObjects.length + ", objects get emtpyed now");
        
        //zur anzeige weiterleiten
        getJSONObjects(midiJSONObjects);
        
        midiJSONObjects=[];
    }
}