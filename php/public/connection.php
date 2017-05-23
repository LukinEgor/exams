<?php
  class Db {
    private static $instance = NULL;

    private function __construct() {}

    private function __clone() {}

    public static function getInstance() {
      if (!isset(self::$instance)) {
        $pdo_options[PDO::ATTR_ERRMODE] = PDO::ERRMODE_EXCEPTION;
        try {
          self::$instance = new PDO('mysql:host=localhost;dbname=exampleDB', 'example_user', 'Admin2015', $pdo_options);
        } catch (Exception $e) {
          require_once('views/pages/error.php');
        }
      }
      return self::$instance;
    }
  }
?>
