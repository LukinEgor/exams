<?php
class StudentsController() {

  public function index() {
    $dao_student = new DaoStudent(Db::getInstance());
    $student = $dao_student.selectAll();
    require_once('views/students/index.php');
  }
}
?>
