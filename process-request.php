<?php


require "/config/Database.php";
require "/modules/Post.php";

header("Access-Control-Allow-Origin: *");
header("Content-Type: application/json; charset=UTF-8");
header("Access-Control-Allow-Methods: OPTIONS,GET,POST,PUT,DELETE");
header("Access-Control-Max-Age: 3600");
header("Access-Control-Allow-Headers: Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With");

$requestMethod = $_SERVER["REQUEST_METHOD"];

if(strtolower(trim($requestMethod))=='post'){

 $db = new Database();
 $requestData = json_decode($_POST);
 $responseObject = new Post($db);
 $response = $responseObject->readRequest($requestData);
 echo json_encode($response);
 

}else if(strtolower(trim($requestMethod))=='get'){


 echo json_encode([
                   "message"=> "GET request not supported in this route",
                   "status"=>false,
                   "code"=>0
                   ]
                  );
}

?>

