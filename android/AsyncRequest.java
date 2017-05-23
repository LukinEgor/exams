package com.example.egor.myapplication;

import android.os.AsyncTask;
import android.util.Log;

import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;


public class AsyncRequest extends AsyncTask<String, Void, JSONObject> {
  public static final String REQUEST_METHOD = "GET";

  @Override
  protected JSONObject doInBackground(String... params){
    String stringUrl = params[0];
    String result = "";
    String inputLine;
    try {
      URL myUrl = new URL(stringUrl);
      HttpURLConnection connection = (HttpURLConnection) myUrl.openConnection();
      connection.setRequestMethod(REQUEST_METHOD);
      connection.connect();
      InputStreamReader streamReader = new InputStreamReader(connection.getInputStream());
      BufferedReader reader = new BufferedReader(streamReader);
      StringBuilder stringBuilder = new StringBuilder();
      while((inputLine = reader.readLine()) != null){
        stringBuilder.append(inputLine);
      }
      reader.close();
      streamReader.close();
      result = stringBuilder.toString();

      return new JSONObject(result);
    } catch (Exception ex){
      Log.d("Error", ex.toString());
    }
    return null;
  }
}
