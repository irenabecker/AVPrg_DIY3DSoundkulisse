$(document).ready(function() {
    // $('.ttt').hide();
    // $('.test2').hide();

    $('#search').keyup(function() {

        // Search text
        var text = $(this).val().toLowerCase();
        var search_result = '';

        
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

        if(search_result.length>0) {
            if($('#item_search').length)
                $('#item_search').html(search_result).addClass('active');
            else
                $('#item_container').append(`<div class="item active" id="item_search">`+search_result+`</div>`);
        }

        if(text.length == 0) {
            $('#item_search').remove();
            $('#itembox_1').addClass('active');
        }

    });

    /* Deaktivert das Enter Drücken auf der Webseite, welches dazu führt das die Seite neugeladen wird */

    $('form input').on('keypress', function(e) {
        return e.which !== 13;
    });

/*
    var all_cards = {
        card_1: {
            shape: 'Dreieck',
            value_1: 100,
            value_2: 1000,
        },
        card_2: {
            shape: 'Viereck',
            value_1: 100,
            value_2: 1000,
        },
        card_3: {
            shape: 'Kreis',
            value_1: 100,
            value_2: 1000,
        },
        card_4: {
            shape: 'Mond',
            value_1: 100,
            value_2: 1000,
        },
    };
*/

    // console.log(JSON.stringify(all_cards));

   /* $.each(all_cards, function(index, value) {
        var _current = all_cards[index];
        new Card($('#itembox_1'), _current.shape);
    }); 
*/
    var cards=[];
    
    cards[0] = new Card($('#itembox_1'), 'Triangle', 'Blue','http://www.memleb.de/UnterrichtsDownLoad/tz/kugel-blau.png', 'soundClip0','soundvolume0','pitch0','configureButton0' );
    cards[1] = new Card($('#itembox_1'), 'Circle', 'Blue', 'https://ae01.alicdn.com/kf/HTB1ikMkIpXXXXX_XpXXq6xXFXXXK/Charming-modeschmuck-perlen-Charming-40mm-Blau-Mexican-Opal-Kugel-Kristallkugel-chalcedon-Gro%C3%9Fhandel-und-einzelhandel.jpg_220x220.jpg','soundClip1','soundvolume1','pitch1','configureButton1');
    cards[2] = new Card($('#itembox_1'), 'Rectangle','Blue','http://web-spiele.de/onlinespiele/tetris-und-co/moonstar/_shot.gif','soundClip2','soundvolume2','pitch2','configureButton2');
    cards[3] = new Card($('#itembox_1'), 'Triangle','Red','http://www.memleb.de/UnterrichtsDownLoad/tz/kugel-blau.png','soundClip3','soundvolume3','pitch3','configureButton3');

    cards[4] = new Card($('#itembox_2'), 'Circle','Red','http://www.memleb.de/UnterrichtsDownLoad/tz/kugel-blau.png','soundClip4','soundvolume4','pitch4','configureButton4' );
    cards[5] = new Card($('#itembox_2'), 'Rectangle','Red','http://www.memleb.de/UnterrichtsDownLoad/tz/kugel-blau.png','soundClip5','soundvolume5','pitch5','configureButton5');
    cards[6] = new Card($('#itembox_2'), 'Triangle','Green','http://www.memleb.de/UnterrichtsDownLoad/tz/kugel-blau.png','soundClip6','soundvolume6','#itch6','configureButton6');
    cards[7] = new Card($('#itembox_2'), 'Circle','Green','http://www.memleb.de/UnterrichtsDownLoad/tz/kugel-blau.png','soundClip7','soundvolume7','pitch7','configureButton7');

    cards[8] = new Card($('#itembox_3'), 'Rectangle','Green','http://www.memleb.de/UnterrichtsDownLoad/tz/kugel-blau.png','soundClip8','soundvolume8','pitch8','configureButton8');

    setSlideDownCards(cards);
    
    for(let i=0; i<cardboxes.length;i++){
        $(document).on("click","#configureButton"+i,function() {


        if($("#soundvolume"+i).is(':disabled')){
            $("#soundClip"+i).removeAttr('disabled');
            $("#soundvolume"+i).removeAttr('disabled');
            $("#pitch"+i).removeAttr('disabled'); 
            $("#configureButton"+i).removeClass("btn-danger");
            $("#configureButton"+i).addClass("btn-success"); 
            $("#configureButton"+i).text('Save');  
        }
        else if($("#soundvolume"+i).is(':enabled')){
            $("#soundClip"+i).prop('disabled',true);
            $("#soundvolume"+i).prop('disabled', true);
            $("#pitch"+i).prop('disabled', true);
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
    },*/
function Card(container, headline,  description, image, soundclipName, soundvolume, pitch, configureButton) {
    this.init(container, headline, description, image, soundclipName,soundvolume, pitch, configureButton);
}

Card.prototype = {

    init: function(container, headline, description, image, soundclipName,soundvolume,pitch,configureButton) {

        this.headline = headline;   //shape
        this.container = container; 
        this.description =  description;    //color
        this.image = image;
        this.soundclipName = soundclipName;
        this.soundvolume =soundvolume;
        this.pitch = pitch;
        this.configureButton = configureButton;
        this.defaultSoundObject=findCorrespondingDefaultSoundObject( headline.toLowerCase(), description.toLowerCase());

        this.createCard();
    },
  
    createCard: function() {

        var that = this;
        i = cardboxes.length;
/*
<select id="selectList">
            <option value="natSound1.wav">NatSound1</option>
            <option value="natSound2.wav">NatSound2</option>
            <option value="citySound1.wav">CitySound1</option>
        </select>
*/
        cardboxes[i] = `<div class="col-sm-3 content" id="card_`+i+`" style="padding-top: 2%; margin-left: -0.1%!important;">
                <div class="thumbnail figures" style="background-color:#cac5c5;!important">
                    <img src="`+that.image+`" alt="fake image" class="img-responsive">
                    <div class="caption">
                        <h4 id="`+that.headline+`">`+that.headline+`</h4>
                        <p><strong>Color:  </strong><div id="`+that.description+`">`+that.description+`</div></p>
                        <p><strong>Soundclip:</strong><select id="`+that.soundclipName+`" style="background: #05080a!important; color: white!important;" disabled></select></p>

                    <form>
                        <strong>Volume:</strong>
                        <div id="slider">
                            <input class="bar" type="range" id="`+that.soundvolume+`" value="0" min="-3" max="3" step="0.1"  oninput="rangevalue.value=value"  disabled/>
                            <span class="highlight"></span>
                            <output class="rangevalue" id="rangevalue">0</output>
                        </div>   
                    </form>     
                    <form">
                        <strong>Pitch:</strong>
                        <div id="slider">
                            <input class="bar" type="range" id="`+that.pitch+`" value="0" min="-3" max="3" step="0.1" joninput="rangevalue.value=value" disabled/>
                            <span class="highlight"></span>
                            <output id="rangevalue">50</output>
                        </div>   
                    </form>  
                    <br>
                    <button type="button" id="`+that.configureButton+`" class="btn btn-danger btn-sm col-sm-6 col-sm-offset-3">Configure</button>
                    <br>
                    </div>
                </div>
            </div>`;

        this.container.append(cardboxes[i]);
    },
};