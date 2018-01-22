$(document).ready(function() {
    $('#search').keyup(function() {

        // Search text
        var text = $(this).val().toLowerCase();
        var search_result = '';

        // remove the class active, so its not active anymore
        $('#item_container').find('.item').each(function(){
            $(this).removeClass('active');
        });

/*
        for (var i = cardboxes.length - 1; i >= 0; i--) {
            if($(cardboxes[i]).text().toLowerCase().indexOf(text) != -1) {
                search_result += cardboxes[i];
            }
        }
        var tempArray=[];
        for(var i=0;i<cardboxes.length;i++)
        {
            tempArray[i]=cardboxes[i];
        }
        cardboxes=[];
        for(var i=0;i<search_result.length;i++)
        {
            cardboxes[i]=search_result[i];
            for(var j=0;j<tempArray.length;j++)
            {
                if(tempArray[j]==search_result[i])
               {
                    tempArray[j].remove();
               }
            }
        }
        //append doesn't work here. use for loop instead or merge arrays?
        //cardboxes.append(tempArray);
*/
        // if an item is found, so set it to active
        if(search_result.length>0) {
            if($('#item_search').length)
                $('#item_search').html(search_result).addClass('active');
            else
                $('#item_container').append(`<div class="item active" id="item_search">`+search_result+`</div>`);
        }

        // Set the list of the item search to zero
        if(text.length == 0) {
            $('#item_search').remove();
            $('#itembox_1').addClass('active');
        }

    });

    /* disable the button that you can't press enter to search */

    $('form input').on('keypress', function(e) {
        return e.which !== 13;
    });


    /*Create the cards for the slider*/
    var cards=[];
    
    cards[0] = new Card($('#itembox_1'), 'Triangle', 'Blue','resources/BlueTriangle.png', 'soundClip0','soundvolume0','configureButton0' );
    cards[1] = new Card($('#itembox_1'), 'Circle', 'Blue', 'resources/BlueCircle.png','soundClip1','soundvolume1','configureButton1');
    cards[2] = new Card($('#itembox_1'), 'Rectangle','Blue','resources/BlueRectangle.png','soundClip2','soundvolume2','configureButton2');
    cards[3] = new Card($('#itembox_1'), 'Triangle','Red','resources/RedTriangle.png','soundClip3','soundvolume3','configureButton3');

    cards[4] = new Card($('#itembox_2'), 'Circle','Red','resources/RedCircle.png','soundClip4','soundvolume4','configureButton4' );
    cards[5] = new Card($('#itembox_2'), 'Rectangle','Red','resources/RedRectangle.png','soundClip5','soundvolume5','configureButton5');
    cards[6] = new Card($('#itembox_2'), 'Triangle','Green','resources/GreenTriangle.png','soundClip6','soundvolume6','configureButton6');
    cards[7] = new Card($('#itembox_2'), 'Circle','Green','resources/GreenCircle.png','soundClip7','soundvolume7','configureButton7');

    cards[8] = new Card($('#itembox_3'), 'Rectangle','Green','resources/GreenRectangle.png','soundClip8','soundvolume8','configureButton8');

    setSlideDownCards(cards);
    
    /*if you press the configure button on each item */

    for(let i=0; i<cardboxes.length;i++){
        $(document).on("click","#configureButton"+i,function() {

        if($("#soundvolume"+i).is(':disabled')){
            $("#soundClip"+i).removeAttr('disabled');
            $("#soundvolume"+i).removeAttr('disabled');
            $("#configureButton"+i).removeClass("btn-danger");
            $("#configureButton"+i).addClass("btn-success"); 
            $("#configureButton"+i).text('Save');  
        }
        else if($("#soundvolume"+i).is(':enabled')){
            $("#soundClip"+i).prop('disabled',true);
            $("#soundvolume"+i).prop('disabled', true);
            $("#configureButton"+i).removeClass("btn-success");
            $("#configureButton"+i).addClass("btn-danger");
            $("#configureButton"+i).text('Configure');  
            saveDefaultCard(i);
        }
        });
    }
});


var cardboxes = [];

/*function Card(container, image, index) {
    this.init(container, image, index);
}

Card.prototype = {

    init: function(container, image, index) {

        this.container = container;
        this.image = image;
        this.index = index;
        this.createCard();
    },
*/

/**/

function Card(container, headline,  description, image, soundclipName, soundvolume, configureButton) {
    this.init(container, headline, description, image, soundclipName,soundvolume, configureButton);
}

/*Create the Prototype for the cards*/
Card.prototype = {

    init: function(container, headline, description, image, soundclipName,soundvolume,configureButton) {

        this.headline = headline;   //shape
        this.container = container; 
        this.description =  description;    //color
        this.image = image;
        this.soundclipName = soundclipName;
        this.soundvolume =soundvolume;
        this.configureButton = configureButton;
        this.defaultSoundObject=findCorrespondingDefaultSoundObject( headline.toLowerCase(), description.toLowerCase());

        this.createCard();
    },
  
    /*The Setup for one card*/
    createCard: function() {

        var that = this;
        i = cardboxes.length;
        
        cardboxes[i] = `<div class="col-sm-3 content padding-top-2 margin-left-0-1" id="card_`+i+`">
                            <div class="thumbnail figures">
                                <img src="`+that.image+`" alt="fake image" class="img-responsive">
                                <div class="caption">
                                        <h3 class="text-center black"id="`+that.headline+`">`+that.headline+`</h3>
                                        <p class="black"><strong>Color:</strong><strong>`+that.description+`</strong></p>
                                        <p><select id="`+that.soundclipName+`" class="likeBlack white" disabled></select></p>

                                    <form>
                                        <strong class="black">Volume:</strong>
                                        <div id="slider">
                                            <input class="bar" type="range" id="`+that.soundvolume+`" value="0" min="-3" max="3" step="0.1"  oninput="rangevalue.value=value"  disabled/>
                                            <span class="highlight"></span>
                                            <output class="rangevalue" id="rangevalue">0</output>
                                        </div>   
                                    </form>
                                    <br>                  
                                    <button type="button" id="`+that.configureButton+`" class="btn btn-danger btn-sm col-sm-6 col-sm-offset-3">Configure</button>
                                    <br>
                                    <br>
                                </div>
                            </div>
                        </div>`;

        this.container.append(cardboxes[i]);
    },
};