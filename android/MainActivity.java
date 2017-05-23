package com.example.egor.myapplication;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.GridView;
import android.widget.TextView;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.concurrent.ExecutionException;

public class MainActivity extends AppCompatActivity {

    ArrayAdapter<String> adapter;
    ArrayList<String> values;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        values = new ArrayList<String>();
        adapter = new ArrayAdapter<String>(this, R.layout.list,R.id.text, values);

        GridView gvMain = (GridView) findViewById(R.id.gridView);
        gvMain.setAdapter(adapter);
    }

    public void buttonClick(View view) {
        String keyword = ((TextView)findViewById(R.id.textView)).getText().toString();
        Log.d("Log", keyword);
        JSONObject response = makeVkRequest(keyword);
        Log.d("Log", response.toString());
        try {
            ArrayList<String> result = ConvertToArray(response);
            Log.d("Log", result.toString());
            values.clear();
            values.addAll(result);
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

    private JSONObject makeVkRequest(String keyword) {
        String url = VkApi.getNewsfeed(keyword);
        AsyncRequest getRequest = new AsyncRequest();
        JSONObject result = null;
        try {
            result = getRequest.execute(url).get();
        } catch (InterruptedException e) {
            e.printStackTrace();
        } catch (ExecutionException e) {
            e.printStackTrace();
        }
        return result;
    }

    private ArrayList<String> ConvertToArray(JSONObject response) throws JSONException {
        JSONArray array = response.getJSONArray("response");
        ArrayList<String> list = new ArrayList<String>();
        for(int i = 1; i < array.length(); i++){
            list.add(array.getJSONObject(i).get("text").toString());
        }

        return list;
    }
}