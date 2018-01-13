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

    <section role="main" style="margin-top: 0%!important;">
        <div class="container">
            <div class="row">
                <div class="col-sm-12 well">
            <div class="col-sm-5 col-sm-offset-1 " style="border-right:3px solid #000000; height: 440px!important;"> 
               <video autoplay="true" id="videoElement" style="height: 100%; padding-left:8%!important;"></video>      
                 <script src='videoStreaming.js' type='text/javascript'></script>           
            </div>
            <div class="col-sm-2 " style="width: 40%;">       
                 <?php include("Hierarchy.html") ?>
            </div>
                </div>
            </div>
        </div>
    </section>

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