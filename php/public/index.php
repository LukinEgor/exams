<?php
  try {
    require_once('connection.php');

    if (isset($_GET['controller']) && isset($_GET['action'])) {
      $controller = $_GET['controller'];
      $action     = $_GET['action'];
    } else {
      $controller = 'pages';
      $action     = 'home';
    }
    require_once('views/layout.php');
  } catch(Exception $e) {
    require_once('views/pages/error.php');
  }
?>
