<?php
class StudentsController {
  public function index() {

    $dao_student = new StudentDao(10, "fdfdd", "fdfds");
    /* $student = $dao_student.selectAll(); */

    require_once('views/pages/error.php');
  }
}
?>
