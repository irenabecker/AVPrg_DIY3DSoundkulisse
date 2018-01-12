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
            headline: 'Dreieck',
            value_1: 100,
            value_2: 1000,
        },
        card_2: {
            headline: 'Viereck',
            value_1: 100,
            value_2: 1000,
        },
        card_3: {
            headline: 'Kreis',
            value_1: 100,
            value_2: 1000,
        },
        card_4: {
            headline: 'Mond',
            value_1: 100,
            value_2: 1000,
        },
    };
*/

    // console.log(JSON.stringify(all_cards));

   /* $.each(all_cards, function(index, value) {
        var _current = all_cards[index];
        new Card($('#itembox_1'), _current.headline);
    }); 
*/
    var card_0 = new Card($('#itembox_1'), 'Dreieck', 'Blau','http://www.memleb.de/UnterrichtsDownLoad/tz/kugel-blau.png', 'Vogelgeschwitzer','soundvolume0','pitch0','configureButton0' );
    var card_1 = new Card($('#itembox_1'), 'Kreis', 'Blau', 'https://ae01.alicdn.com/kf/HTB1ikMkIpXXXXX_XpXXq6xXFXXXK/Charming-modeschmuck-perlen-Charming-40mm-Blau-Mexican-Opal-Kugel-Kristallkugel-chalcedon-Gro%C3%9Fhandel-und-einzelhandel.jpg_220x220.jpg','Vogelgeschwitzer','soundvolume1','pitch1','configureButton1');
    var card_2 = new Card($('#itembox_1'), 'Rechteck','Blau','http://web-spiele.de/onlinespiele/tetris-und-co/moonstar/_shot.gif','Vogelgeschwitzer','soundvolume2','pitch2','configureButton2');
    var card_3 = new Card($('#itembox_1'), 'Dreieck','Rot','http://www.memleb.de/UnterrichtsDownLoad/tz/kugel-blau.png','Vogelgeschwitzer','soundvolume3','pitch3','configureButton3');

    var card_4 = new Card($('#itembox_2'), 'Kreis','Rot','http://www.memleb.de/UnterrichtsDownLoad/tz/kugel-blau.png','Vogelgeschwitzer','soundvolume4','pitch4','configureButton4' );
    var card_5 = new Card($('#itembox_2'), 'Rechteck','Rot','http://www.memleb.de/UnterrichtsDownLoad/tz/kugel-blau.png','Vogelgeschwitzer','soundvolume5','pitch5','configureButton5');
    var card_6 = new Card($('#itembox_2'), 'Dreieck','Grün','http://www.memleb.de/UnterrichtsDownLoad/tz/kugel-blau.png','Vogelgeschwitzer','soundvolume6','pitch6','configureButton6');
    var card_7 = new Card($('#itembox_2'), 'Kreis','Grün','http://www.memleb.de/UnterrichtsDownLoad/tz/kugel-blau.png','Vogelgeschwitzer','soundvolume7','pitch7','configureButton7');

    var card_8 = new Card($('#itembox_3'), 'Rechteck','Grün','http://www.memleb.de/UnterrichtsDownLoad/tz/kugel-blau.png','Vogelgeschwitzer','soundvolume8','pitch8','configureButton8');

    for(let i=0; i<cardboxes.length;i++){
        $(document).on("click","#configureButton"+i,function() {


        if($("#soundvolume"+i).is(':disabled')){
            $("#soundvolume"+i).removeAttr('disabled');
            $("#pitch"+i).removeAttr('disabled'); 
            $("#configureButton"+i).removeClass("btn-danger");
            $("#configureButton"+i).addClass("btn-success"); 
            $("#configureButton"+i).text('Save');  
        }
        else if($("#soundvolume"+i).is(':enabled')){
            $("#soundvolume"+i).prop('disabled', true);
            $("#pitch"+i).prop('disabled', true);
            $("#configureButton"+i).removeClass("btn-success");
            $("#configureButton"+i).addClass("btn-danger");
            $("#configureButton"+i).text('Configure');  
        }
            
        });


    }
});


var cardboxes = [];

function Card(container, headline,  description, image, soundclipName, soundvolume, pitch, configureButton) {
    this.init(container, headline, description, image, soundclipName,soundvolume, pitch, configureButton);
}

Card.prototype = {

    init: function(container, headline, description, image, soundclipName,soundvolume,pitch,configureButton) {

        this.headline = headline;
        this.container = container;
        this.description =  description;
        this.image = image;
        this.soundclipName = soundclipName;
        this.soundvolume = soundvolume;
        this.pitch = pitch;
        this.configureButton = configureButton;

        this.createCard();
    },

    createCard: function() {

        var that = this;
        i = cardboxes.length;

        cardboxes[i] = `<div class="col-sm-3 content" id="card_`+i+`" style="padding-top: 2%; margin-left: -0.1%!important;">
                <div class="thumbnail figures" style="background-color:#cac5c5;!important">
                    <img src="`+that.image+`" alt="fake image" class="img-responsive">
                    <div class="caption">
                        <h4>`+that.headline+`</h4>
                        <p><strong>Farbe: </strong>`+that.description+`</p>
                        <p><strong>Soundclip:</strong><i>`+that.soundclipName+`</i></p>


                    <form oninput="x.value=parseInt(`+that.soundvolume+`.value)">
                      <strong>Lautstärke:</strong>
                      <output name="x" for="`+that.soundvolume+`"></output>
                        <input id=`+that.soundvolume+` type="range" min="1" max="100" disabled>
                    </form>

                    <form oninput="y.value=parseInt(`+that.pitch+`.value)">
                      <strong>Pitch:</strong>
                      <output name="y" for="`+that.pitch+`"></output>
                        <input id=`+that.pitch+` type="range" min="0" max="100" disabled>
                    </form>                    

                    <br>
                    <button type="button" id=`+that.configureButton+` class="btn btn-danger btn-sm col-sm-6 col-sm-offset-3">Configure</button>
                    <br>
                    </div>
                </div>
            </div>`;

        this.container.append(cardboxes[i]);
    },
};