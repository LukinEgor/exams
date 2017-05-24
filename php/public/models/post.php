<?php
  class Post {
    public $id;
    public $author;
    public $content;

    public function __construct($id, $author, $content) {
      $this->id      = $id;
      $this->author  = $author;
      $this->content = $content;
    }

    public static function init() {
      $db = Db::getInstance();
      $param = 'CREATE TABLE IF NOT EXISTS posts( id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY, author VARCHAR(30) NOT NULL, content VARCHAR(30) NOT NULL)';
      $req = $db->query($param);
    }

    public static function all() {
      /* try { */
      /*   Post::init(); */
      /* } catch(Exception $e) { */
      /*   require_once('views/pages/error.php'); */
      /* } */

      $list = [];
      $db = Db::getInstance();
      $req = $db->query('SELECT * FROM posts');

      foreach($req->fetchAll() as $post) {
        $list[] = new Post($post['id'], $post['author'], $post['content']);
      }

      return $list;
    }

    public static function find($id) {
      $db = Db::getInstance();

      $id = intval($id);
      $req = $db->prepare('SELECT * FROM posts WHERE id = :id');

      $req->execute(array('id' => $id));
      $post = $req->fetch();

      return new Post($post['id'], $post['author'], $post['content']);
    }

    public static function create($author, $content) {
      $db = Db::getInstance();

      $req = $db->prepare('INSERT INTO posts VALUES(0, :author, :content)');
      $req->execute(array('author' => $author, 'content' => $content));
      $id = mysql_insert_id();

      $id = intval($id);
      $req = $db->prepare('SELECT * FROM posts WHERE id = :id');

      $req->execute(array('id' => $id));
      $post = $req->fetch();

      return new Post($post['id'], $post['author'], $post['content']);
    }
  }
?>
