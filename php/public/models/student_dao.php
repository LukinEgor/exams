<?php

class StudentDao extends Dao {
  protected $_primaryKey = "id";
  protected $_tableName = "students";

  public function __constructor() {
    parent::__construct()
    this->initTable();
  }

  public function initTable() {
    $_connection->query("CREATE TABLE IF NOT EXISTS students(id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY_KEY, name TEXT)");
  }
}
