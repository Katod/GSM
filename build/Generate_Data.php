#!/usr/bin/php
<?php

class MyDB extends SQLite3
   {
      function __construct()
      {
         $this->open('GSM');
      }
   }
  

function cache_update($text) {
  echo "text=".$text."\n";
  $words = explode(",", $text);
  $cnt=count($words);
  echo "count words ". $cnt."\n";
  $command ="avconv -i concat:";

  for ($i=0;$i<$cnt;$i++) {

    if(trim($words[$i])!="")
    {
      $file=str_replace(" ","",$words[$i]).".mp3";
      $command.=str_replace(" ","",$words[$i]).".mp3\|";

      echo "file=".$file."\n";
      if (file_exists($file)) {
        echo "Skip updating " . $file . "\n";
      } else {
        echo "Generating file " . $file . "\n";
        file_put_contents($file, file_get_contents("http://s2.smarthouse.ua:8080/say_mp3.php?text=" . urlencode($words[$i])));
      }
    }
  }
  
  $command.=" -c copy /home/html/status.mp3 -y";
  exec("cd /home/sh2/exe");
  echo "Command =".$command;
  exec($command);

}
   $db = new MyDB();
   if(!$db){
      echo $db->lastErrorMsg();
   } else {
      echo "Opened database successfully\n";
   }

$sql =<<<EOF
      SELECT * from clients;
EOF;

   $ret = $db->query($sql);
   while($row = $ret->fetchArray(SQLITE3_ASSOC) ){
      echo "ID = ". $row['id'] . "\n";
      echo "NAME = ". $row['phone_number'] ."\n";
   }
   echo "Operation done successfully\n";
   $db->close();

//cache_update($text);

?>
