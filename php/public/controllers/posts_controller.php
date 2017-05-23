<?php
  class PostsController {
    public function index() {
      $posts = Post::all();
      require_once('views/posts/index.php');
    }

    public function show() {
      if (!isset($_GET['id']))
        return call('pages', 'error');

      $post = Post::find($_GET['id']);
      require_once('views/posts/show.php');
    }

    public function make() {
      require_once('views/posts/make.php');
    }

    public function create() {
      $author = $_GET['author'];
      $content = $_GET['content'];

      Post::create($author, $content);

      $posts = Post::all();
      require_once('views/posts/index.php');
    }
  }
?>
