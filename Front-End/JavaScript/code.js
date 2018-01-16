var midiJSONObjects=[];


function initialize(){
    
    //for testing without backend
    /*let counter=0;
    setTimeout(function () {
        
        window.setInterval(function()
        {
            counter;
            let direction=1;
            counter+=(10*direction);
            if(counter>=100)
                {
                    direction*=-1;
                }
            createJSONObject('RECTANGLE','RED', counter, 20, 30);
            resetJSONObjects();
        },2000)
    }, 5000);
    */
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
        //log all data in console
        var out="";
        for(var i=0;i<event.data.length;i++)
            {
                out+=" event data["+i+"]:"+event.data[i];
            }
        
        if((event.data[0]&0xf0)==0xC0)
        {
            resetJSONObjects(); 
            return;
        }
        
        //get channel = Color
        var channel=event.data[1]&0x0f;
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
        let shape='';
      switch (event.data[1] & 0xf0) {
        case 0x00:
			shape = 'RECTANGLE';
			break;
        case 0x10:
              shape = 'CIRCLE';
			break;
		case 0x20:
              shape = 'TRIANGLE';
			break; 
      }
    
    if (shape.length != 0)
        createJSONObject(shape,color,event.data[2], event.data[3],event.data[4]);
    }
    
	function createJSONObject(shape,color,posX,posY,posZ){
        midiJSONObjects.push('{' +
            '"shape":"'+shape.toLowerCase()+'",' +
            '"color":"'+color.toLowerCase()+'",' +
            '"xPosition":'+posX+',' +
            '"yPosition":'+posY+',' +
            '"zPosition":'+posZ+ 
        '}');
        console.log("Shape: "+shape+ " color: "+color+", PosX: "+posX+", PosY: "+posY+", PosZ: "+posZ);
	}
    
    function resetJSONObjects()
    {
        console.log(midiJSONObjects.length + ", objects get emtpyed now");
        
        //zur anzeige weiterleiten
        getJSONObjects(midiJSONObjects);
        
        midiJSONObjects=[];
    }
}