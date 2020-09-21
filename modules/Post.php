<?php


class Post {
    // DB properties................ 
    private $conn;
    private $table = 'users';

    // Post properties...................... 

    public $name;
    public $age;

    // Constructor method..................... 

    public function __construct($db){
        $this->conn = $db;
      
    }

    // Post Read................................ 

    public function readRequest($data){

       if(is_object($data)){
       
       $name = htmlentities($data->name, ENT_QUOTES);      
        $age = htmlentities($data->age, ENT_QUOTES);       
        


       

$sql="INSERT INTO `users`( `name`, `age`) VALUES ( :name, :age)";


       try {
            $stmt=$this->db->prepare($sql);

            $stmt->bindParam(':name',$name,PDO::PARAM_STR);
            $stmt->bindParam(':age',$age,PDO::PARAM_STR);
           
      
            $query_status=$stmt->execute();
          
     // echo var_dump($stmt);
            if ($query_status==true) {
               
                  
                   $result =[
                   "message"=> "Request processed successfully",
                   "status"=>true,
                   "code"=>200
                   ];
                  
               
                 return $result;
            }else{
                  $result =[
                   "message"=> "Error Occurred",
                   "status"=>false,
                   "code"=>-1
                   ];
                  
               
                 return $result;
            }

            $stmt->closeCursor();

           
        } catch (Exception $e) {
            die ( $e->getMessage() );   


	}
	
	
       }else{
       return "Not Object";
       
       }
        
       
        
    


}
}