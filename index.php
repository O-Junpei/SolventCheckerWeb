<?php 
  date_default_timezone_set('UTC');
  $jsonUrl = "log.json"; 
  $obj;

  if(file_exists($jsonUrl)){
    $json = file_get_contents($jsonUrl);
    $json = mb_convert_encoding($json, 'UTF8', 'ASCII,JIS,UTF-8,EUC-JP,SJIS-WIN');
    $obj = json_decode($json,true);
  }else {
    echo "データがありません";
  }

 ?> 


<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <title>トップページ</title>
  <!-- Latest compiled and minified CSS -->
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">

</head>
<body>

  <header id="header" class="container">
    <h1 class="text-center">ようえきちぇっか～</h1>
    <button type="button" class="btn btn-primary btn-lg btn-block" onClick="window.open('/export.php')")>PDF Export</button>
  </header><!-- /header -->


  <div class="container">
    <table class="table table-inverse">
      <thead>
        <tr>
          <th>#</th>
          <th>日にち</th>
          <th>液量</th>
        </tr>
      </thead>
      <tbody>
        <?php
          $i = 0;
          foreach ($obj as $key => $val){
            $i ++;
            echo "<tr>";
            echo "<th scope=\"row\">";
            echo $i;
            echo "</th>";
            echo "<td>";
            echo $val["year"]."/".$val["month"]."/".$val["day"]." ".$val["hour"].":".$val["minute"].":".$val["second"];
            echo "</td><td>";
            echo $val["data"]." L";
            echo "</td></tr>";
          }
        ?>
      </tbody>
    </table>
  </div>

    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
</body>
</html>