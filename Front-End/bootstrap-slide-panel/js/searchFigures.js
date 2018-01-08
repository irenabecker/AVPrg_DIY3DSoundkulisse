$(document).ready(function() {
    // $('.ttt').hide();
    // $('.test2').hide();

    $('#search').keyup(function() {

        // Search text
        var text = $(this).val().toLowerCase();
        // Hide all content class element
        $('.content').hide();

        // Search 
        $('.content .figures').each(function() {

            if ($(this).text().toLowerCase().indexOf("" + text + "") != -1 && $(this).text().length > 0) {

                $(this).closest('.content').show();

            }
        });
    });

    /* Deaktivert das Enter Drücken auf der Webseite, welches dazu führt das die Seite neugeladen wird */

    $('form input').on('keypress', function(e) {
        return e.which !== 13;
    });


});