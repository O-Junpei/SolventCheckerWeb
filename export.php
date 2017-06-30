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

//$count = 0;
//foreach ($obj as $key => $val){

  $mpdf->WriteHTML(sprintf($tempDiv, 370, 73, '0.8rem', '2017.06.03'));
  $mpdf->WriteHTML(sprintf($tempDiv, 401, 73, '0.8rem', '2017.12.03'));
  $mpdf->WriteHTML(sprintf($tempDiv, 432, 73, '0.8rem', '2017.12.03'));
  $mpdf->WriteHTML(sprintf($tempDiv, 463, 73, '0.8rem', '2017.12.03'));
  $mpdf->WriteHTML(sprintf($tempDiv, 494, 73, '0.8rem', '2017.12.03'));
  $mpdf->WriteHTML(sprintf($tempDiv, 525, 73, '0.8rem', '2017.12.03'));
  $mpdf->WriteHTML(sprintf($tempDiv, 556, 73, '0.8rem', '2017.12.03'));

  $mpdf->WriteHTML(sprintf($tempDiv, 365, 350, '1.3rem', '04.80L'));
  $mpdf->WriteHTML(sprintf($tempDiv, 396, 350, '1.3rem', '04.80L'));
  $mpdf->WriteHTML(sprintf($tempDiv, 427, 350, '1.3rem', '04.80L'));
  $mpdf->WriteHTML(sprintf($tempDiv, 458, 350, '1.3rem', '04.80L'));
  $mpdf->WriteHTML(sprintf($tempDiv, 489, 350, '1.3rem', '04.80L'));
  $mpdf->WriteHTML(sprintf($tempDiv, 520, 350, '1.3rem', '04.80L'));
  $mpdf->WriteHTML(sprintf($tempDiv, 520, 350, '1.3rem', '04.80L'));
  //$count = $count+1;
//}




$mpdf->WriteHTML('</div>');
 
// PDFを出力
$mpdf->Output();