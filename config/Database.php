<?php

    class Database  {
        
        // Connection param.................... 

        private $serverName = 'localhost';
        private $dbName = 'arduino';
        private $userName = 'root';
        private $password = 'password123$';
        private $conn;

        // DB Connect.................................. 

        public function connection (){

            $this->conn = null;

            try {

                $this->conn = new PDO('mysql:host='. $this-> serverName. ';dbName='. $this->dbName,
                 $this->userName, $this->password );
                $this->conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXECPTION);

            } catch (PDOExecption $conn_errormsg){
                echo 'Connection failed :' .$conn_errormsg->getMessage();
            }
            echo 'hello Database.php';
            return $this->conn;
        }

    }
    

