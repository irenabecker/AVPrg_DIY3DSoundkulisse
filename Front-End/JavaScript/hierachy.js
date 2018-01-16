//var hierachyHTMLObjects=[];
var hierachyHTMLObjects = [];
let i;

function Obj(container, shape, color, soundclipName,soundvolume,configButton,resetButton,  soundElementInScene, defaultSoundObject,index) {
    this.init(container, shape, color, soundclipName,soundvolume,configButton,resetButton,  soundElementInScene, defaultSoundObject,index);
}

Obj.prototype = {

    init: function(container, shape, color, soundclipName,soundvolume,configButton,resetButton, soundElementInScene,defaultSoundObject,index) {

        this.container = container;
        this.shape = shape; 
        this.color =  color;
        this.soundclipName = soundclipName;
        this.soundvolume =soundvolume;
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

        hierachyHTMLObjects[this.index] = `<div class="col-sm-12" id="index`+that.index+`">
    	<button data-toggle="collapse" data-target="#demo`+that.index+`" id="btn`+that.index+`" onclick="colorchange('btn`+that.index+`')" class="font-size-19 FigurObject border-groove" style="width: 269px;background: white;!important">`+that.color+` `+that.shape+`</button>  
	</div>

    <div id="demo`+that.index+`" class="collapse">
            <div class="col-sm-12">
                <div class="border-groove padding-bottom-5">
                <form class="margin-right-25">
                    <strong>Volume:</strong>
                    <div id="slider">
                        <input class="bar" type="range" id=`+that.soundvolume+` value="0" min="-3" max="3" step="0.1"  oninput="rangevalue.value=value" disabled/>
                        <span class="highlight"></span>
                        <output class="rangevalue" id="rangevalue">50</output>
                    </div>   
                </form>  
                    <button type="button" class="btn btn-xs btn-danger btn-change col-sm-offset-2" id="`+that.resetButton+`" onclick="resetHierachyObject('`+that.index+`')">Reset to Default </button>

                    <button type="button" class="btn btn-danger btn-warning btn-xs btn-change" id="`+that.configButton+`" onclick="configureHierachy('`+that.index+`')">Configure</button>
                </form>
            </div>
    </div>
</div>`;
        

        this.container.insertAdjacentHTML('beforeend', hierachyHTMLObjects[this.index]);
        //this.container.append(hierachyHTMLObjects[i]);
    },
};

function colorchange(id) {
    var obj=document.getElementById("btn"+id);
            var background = obj.style.backgroundColor;
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
        $("#hierachyConfigButton"+i).removeClass("btn-danger");
        $("#hierachyConfigButton"+i).addClass("btn-success"); 
        $("#hierachyConfigButton"+i).text('Save');  
    }
    else if($("#hierachyVolume"+i).is(':enabled')){
        $("#hierachyVolume"+i).prop('disabled', true);
        $("#hierachyConfigButton"+i).removeClass("btn-success");
        $("#hierachyConfigButton"+i).addClass("btn-danger");
        $("#hierachyConfigButton"+i).text('Configure');  
        saveHierachyObject(i); 
     }
}