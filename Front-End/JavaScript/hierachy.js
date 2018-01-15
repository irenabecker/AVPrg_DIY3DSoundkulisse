//var hierachyHTMLObjects=[];
var hierachyHTMLObjects = [];
let i;

function Obj(container, shape, color, soundclipName,soundvolume, pitch,configButton,resetButton,  soundElementInScene, defaultSoundObject,index) {
    this.init(container, shape, color, soundclipName,soundvolume, pitch,configButton,resetButton,  soundElementInScene, defaultSoundObject,index);
}

Obj.prototype = {

    init: function(container, shape, color, soundclipName,soundvolume, pitch,configButton,resetButton, soundElementInScene,defaultSoundObject,index) {

        this.container = container;
        this.shape = shape; 
        this.color =  color;
        this.soundclipName = soundclipName;
        this.soundvolume =soundvolume;
        this.pitch = pitch; 
        this.soundElementInScene=soundElementInScene;
        this.defaultSoundObject=defaultSoundObject;
        this.index=index;
        this.configButton=configButton;
        this.resetButton=resetButton;

        this.createObj();
    },
    
    createObj: function() {

        var that = this;
        i = hierachyHTMLObjects.length;

        hierachyHTMLObjects[i] = `<div class="col-sm-12 padding-left-0" id="index`+i+`">
    	<button data-toggle="collapse" data-target="#demo`+i+`" id="btn`+i+`" onclick="colorchange('`+i+`')" class="font-size-19 FigurObject" style="background:white;">Shape:  `+that.shape+` Color: `+that.color+`</button>  
	</div>
    <div id="demo`+i+`" class="collapse">
            <div class="col-sm-9 border-groove" style="width: 100%;">

                <form>
                    <strong>Volume:</strong>
                    <div id="slider">
                        <input class="bar" type="range" id=`+that.soundvolume+` value="0" min="-3" max="3" step="0.1"  oninput="rangevalue.value=value" disabled/>
                        <span class="highlight"></span>
                        <output class="rangevalue" id="rangevalue">50</output>
                    </div>   
                </form>  
                
                <form>
                    <strong>Pitch:</strong>
                    <div id="slider">
                        <input class="bar" type="range" id="`+that.pitch+`" value="0" min="-3" max="3" step="0.1"  oninput="rangevalue.value=value" disabled/>
                        <span class="highlight"></span>
                        <output id="rangevalue">50</output>
                    </div>   
                </form>

                <div class="col-sm-3 col-sm-offset-1">
                    <button type="button" class="btn btn-xs btn-danger btn-change" id="`+that.resetButton+`" onclick="resetHierachyObject('`+that.index+`')">Reset to Default </button>
                </div>
                <div class="col-sm-3 col-sm-offset-2 padding-bottom-5">
                    <button type="button" class="btn btn-danger btn btn-xs btn-change" id="`+that.configButton+`" onclick="configureHierachy('`+that.index+`')">Configure</button>
                </div>
            </div>
    </div>`;
        

        this.container.insertAdjacentHTML('beforeend', hierachyHTMLObjects[i]);
        //this.container.append(hierachyHTMLObjects[i]);
    },
};

function colorchange(id) {
    var obj=document.getElementById("btn"+id);
            var background = document.getElementById("btn"+id).style.backgroundColor;
            if (background == "white") {
                document.getElementById("btn"+id).style.background = "rgb(26,255,0)";
            } else {
                document.getElementById("btn"+id).style.background = "white";
            }      
}

function configureHierachy(i)
{
    if($("#hierachyVolume"+i).is(':disabled')){
        $("#hierachyVolume"+i).removeAttr('disabled');
        $("#hierachyPitch"+i).removeAttr('disabled'); 
        $("#hierachyConfigButton"+i).removeClass("btn-danger");
        $("#hierachyConfigButton"+i).addClass("btn-success"); 
        $("#hierachyConfigButton"+i).text('Save');  
    }
    else if($("#hierachyVolume"+i).is(':enabled')){
        $("#hierachyVolume"+i).prop('disabled', true);
        $("#hierachyPitch"+i).prop('disabled', true);
        $("#hierachyConfigButton"+i).removeClass("btn-success");
        $("#hierachyConfigButton"+i).addClass("btn-danger");
        $("#hierachyConfigButton"+i).text('Configure');  
        saveHierachyObject(i); 
     }
}