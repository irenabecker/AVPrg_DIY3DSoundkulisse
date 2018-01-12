<!DOCTYPE html>
<html>

<head>
    <title>AVPRG-Projekt</title>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">
    <link href="page.css" rel="stylesheet" type="text/css" />
    <link href="slider.css" rel="stylesheet" type="text/css" />
</head>

<body>
        <?php include("background-carousel/background-carousel.php") ?>
         <div class="row">
            <div class="col-md-12">       
              <?php include("bootstrap-slide-panel/topSlide.html") ?>
            </div>
        </div>
    <div class="row">
        <div class="col-sm-5 well" style="border:1px solid #000000; height: 440px!important; margin-left: 13.7%!important;"> 
            <video autoplay="true" id="videoElement" style="height: 100%; padding-left:8%!important;"></video>      
             <script src='videoStreaming.js' type='text/javascript'></script>           
        </div>
        <div class="col-sm-3 well" style="border:1px solid #000000; width: 31%;">       
            <?php include("Hierarchy.html") ?>
        </div>
    </div>
        <footer>
        <div class="container">
            <div class="row">
                <div class="col-sm-12">
                <?php include("footer.html") ?>
                </div>
            </div>
        </div>
    </footer>
    <!-- /footer -->
</body>

</html>