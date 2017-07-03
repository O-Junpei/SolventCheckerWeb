<?php 
// 申込書をmpdfで出力する
// mpdfライブラリ
include("mpdf60/mpdf.php");

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



$mpdf=new mPDF('ja', 'A4');
// utf8でエラーが起こらないようにする
$mpdf->ignore_invalid_utf8 = true;
// PDFをインポートして下敷きとして使うための設定
$mpdf->SetImportUse();
// 下敷きのPDFを読み込む pagecountにはページ数が入る
$pagecount = $mpdf->SetSourceFile("templete.pdf");
// この場合は1ページしかないので1ページ目をテンプレートとして指定
$tplId = $mpdf->ImportPage(1);
$mpdf->SetPageTemplate($tplId);
 
// ページに値を埋め込む
$mpdf->WriteHTML('<div style="position:relative;"');
 
// 内容用のDIVテンプレート
$tempDiv = '<div style="width:430px;position:absolute;top:%spx;left:%spx;font-size:%s;white-space: nowrap;">%s</div>';

//溶媒のリスト
$solventAry = array("アセトン", "エタノール","メタノール");

//投入者氏名
$nameAry = array("小野(J)", "尾下","佐々木", "石内","鷲尾", "今野","紙谷");

$count = 0;
$beforeData = 0;
foreach ($obj as $key => $val){

  $margin = 31*$count;

  //日時
  $dateStr = "";
  $dateStr = $val["year"]."/".$val["month"]."/".$val["day"];
  $mpdf->WriteHTML(sprintf($tempDiv, 370+$margin, 73, '0.8rem', $dateStr));

  //内容液物
  $solventRand = rand(0, count($solventAry)-1);
  $mpdf->WriteHTML(sprintf($tempDiv, 365+$margin, 150, '1.2rem', $solventAry[$solventRand]));

  //投入者名
  $nameRand = rand(0, count($nameAry)-1);
  $mpdf->WriteHTML(sprintf($tempDiv, 365+$margin, 520, '1.2rem', $nameAry[$nameRand]));

  //データ本体
  $addAmount = "";
  $totalAmount = "";

  if ($count == 0) {
    $addAmount = $val["data"];
  }else{
    $addAmount = (string) (floatval($val["data"])-$beforeData);
  }

  $totalAmount = $val["data"];
  $beforeData = $totalAmount;
  $mpdf->WriteHTML(sprintf($tempDiv, 368+$margin, 350, '1.1rem', $addAmount."/".$totalAmount));

  $count = $count+1;
}




$mpdf->WriteHTML('</div>');
 
// PDFを出力
$mpdf->Output();