<?php
 abstract class Dao {
    protected $_connection;
    protected $_primaryKey;
    protected $_tableName;

    public function __constructor() {
      $this->_connection = Db::getInstance();
    }

    public function selectAll() {
      $query = "select * from ".$this->_tableName;
      $results = $this->_connection->query($query);
      return $result;
    }
 }
?>
