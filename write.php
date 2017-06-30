<?php 
date_default_timezone_set('UTC');

//http://localhost:8000/?pass=1065&data=3452

$password = "";
$data = "";
$message = "";


function saveData($data){

  $jsonUrl = "log.json"; //JSONファイルの場所とファイル名を記述
  $obj;

  if(file_exists($jsonUrl)){
    $json = file_get_contents($jsonUrl);
    $json = mb_convert_encoding($json, 'UTF8', 'ASCII,JIS,UTF-8,EUC-JP,SJIS-WIN');
    $obj = json_decode($json,true);
  }else {
    echo "データがありません";
  }

  // date()で日時を出力
  $timestamp = time() ;
  $nowString = "";
  $nowString = date( "Y/m/d H:i:s" , $timestamp ) ;

  $array = array(
    "date" => $nowString  ,
    "data" => $data );

  $obj[count($obj)] = $array;

  // 連想配列($array)をJSONに変換(エンコード)する
  $json = json_encode( $obj ) ;
  file_put_contents("log.json" , $json);

  return "Success";
}


try {
  $password = $_GET['pass'];
  $data = $_GET['data'];
    if ($password == "1064") {
      $message = "ログイン成功しました。";
      $message = saveData($data);
    }else{
      $message = "パスワードが違います。";
    }
} catch (Exception $e) {
  $message = "エラーです。";
}

  echo $message;
 ?> 
