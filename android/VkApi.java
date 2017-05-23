package com.example.egor.myapplication;

/**
 * Created by egor on 5/23/17.
 */

public class VkApi {
  public static String getNewsfeed(String keyword) {
    String token = "7afc16127afc16127afc1612707aa021ba77afc7afc161223dfc35701471cc85e7b76f2";
    String url = "https://api.vk.com/method/newsfeed.search?access_token=" + token + "&q=" + keyword;
    return url;
  }
}
