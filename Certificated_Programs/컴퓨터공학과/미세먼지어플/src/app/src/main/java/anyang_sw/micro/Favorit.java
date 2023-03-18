/*
미세먼지 알림 프로그램
    즐겨찾기 부분
        작성자 : 조상호

        작성일 : 2018.12.07

        구조 ; 이 프로그램은 다음과 같은 클래스로 구성되어있음
                Favorit :
                    클래스
                        DialogFlagment :  즐겨찾기 추가 버튼의 리스트 및 클릭 이벤트 처리하는 클래스

                    메소드
                        onCreate : 리스트 파일 입출력 및 버튼 이벤트 담당처리.

        공유 변수
                MainActivity 의 fav : 즐겨찾기위치 실행시 위치값("경기 안양시") 등 설정
                ArrayList<String> staticItems : 프로그램 종료시 즐겨찾기 저장하기 위해 즐겨찾기 리스트를 저장

        외부 참조 파일
        fav.txt : 즐겨찾기에 대한 정보 / 위치값("경기 안양시")으로 한줄씩 저장.

 */
package anyang_sw.micro;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.support.v4.app.DialogFragment;
import android.support.v4.app.FragmentManager;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Timer;
import java.util.TimerTask;

public class Favorit extends AppCompatActivity {

    private Button insert;
    private  Button delete;
    private  ListView listView;
    private  ArrayList<String> items;
    private ArrayAdapter<String> arrayAdapter;

 /*   void setPermission(){

        int permissionInfo = ContextCompat.checkSelfPermission(this,Manifest.permission.WRITE_EXTERNAL_STORAGE);

        if(permissionInfo!=PackageManager.PERMISSION_GRANTED)
            ActivityCompat.requestPermissions(this,new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE},100);

    }
    */
    public static ArrayList<String> staticItems;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_favorit);
        startService(new Intent(this, TestService.class));

        listView= findViewById(R.id.favo);
        insert = findViewById(R.id.insert);
        delete = findViewById(R.id.Deletelist);
        staticItems = new ArrayList<String>();
        items = new ArrayList<String>();
        final DialogFlagment df;
       // setPermission();

        File file = new File(getFilesDir()+"/fav.txt") ;

        if(!file .exists()){
            FileWriter fw=null;
            try {
                 fw = new FileWriter(file);
                fw.write("");
            }
            catch(Exception e){
                e.printStackTrace();
            }
            try{
                if(fw!=null)
                    fw.close();
            }
            catch(Exception e){
                e.printStackTrace();
            }
        }
        FileReader fr= null;
        BufferedReader br =null;
        String data ;
        String str ="";

        try {
            // open file.
            fr = new FileReader(file) ;
            br = new BufferedReader(fr);

            // read file.
            while ((data = br.readLine()) != null) {
                // TODO : use data
                str += data +"/" ;
            }

        } catch (Exception e) {
            e.printStackTrace() ;
        }

        staticItems =(ArrayList<String>) items.clone();
        try{
            if(br !=null)
                br.close();
            if(fr!=null)
                fr.close() ;
        }
        catch(Exception e){
            e.printStackTrace();
        }
        if(str.length()!=0) {
            String[] list = str.split("/");
            for (int i = 0; i < list.length; i++) {
                items.add(list[i]);
            }
        }
        else{
            items.add("경기 안양시");
        }

         df = new DialogFlagment();

        arrayAdapter = new ArrayAdapter<String>(this,android.R.layout.simple_list_item_single_choice, items);

        listView.setAdapter(arrayAdapter) ;

        insert.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if (v.getId() == R.id.insert) {
                        File file = new File(getFilesDir() + "/fav.txt");
                        FileWriter fw = null;
                        BufferedWriter bw = null;
                        FragmentManager fm = getSupportFragmentManager();

                        df.show(fm, "");


                        String temp = df.getSelect();
                        if (!items.contains(temp) && !temp.equals("")) {
                            items.add(temp);

                            staticItems = (ArrayList<String>) items.clone();

                            try {

                                fw = new FileWriter(file);
                                bw = new BufferedWriter(fw);

                                for (int i = 0; i < items.size(); i++) {
                                    bw.write(items.get(i));
                                    bw.write("\n");
                                    bw.flush();
                                }
                            } catch (Exception e) {
                                e.printStackTrace();
                            }

                            try {
                                if (bw != null)
                                    bw.close();
                                if (fw != null)
                                    fw.close();
                            } catch (Exception e) {
                                e.printStackTrace();
                            }
                            arrayAdapter.notifyDataSetChanged();

                        }
                }
            }
        });


        delete.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if (v.getId() == R.id.Deletelist) {
                    int count, checked ;
                    count = arrayAdapter.getCount() ;

                    if (count > 0) {
                        // 현재 선택된 아이템의 position 획득.
                        checked = listView.getCheckedItemPosition();

                        File file = new File(getFilesDir()+"/fav.txt") ;
                        FileWriter fw=null;
                        BufferedWriter bw=null;
                        if (checked > -1 && checked < count) {
                            // 아이템 삭제
                            items.remove(checked) ;
                            try {

                                fw = new FileWriter(file);
                                bw = new BufferedWriter(fw);

                                for (int i = 0; i < items.size(); i++) {
                                    bw.write(items.get(i));
                                    bw.write("\n");
                                    bw.flush();
                                }
                            }catch(Exception e){
                                e.printStackTrace();
                            }
                            try {
                                if (bw != null)
                                    bw.close();
                                if (fw != null)
                                    fw.close();
                            }
                            catch(Exception e){
                                e.printStackTrace();
                            }
                            // listview 선택 초기화.
                            listView.clearChoices();

                            // listview 갱신.
                            arrayAdapter.notifyDataSetChanged();
                        }
                    }
                }
            }
        });
        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            int lastPick=-1;
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                if(lastPick == position) {
                    MainActivity.fav = items.get(position);
                    MainActivity.df.setSelect("");
                    finish();
                }
                lastPick = position;
            }
        });

    }

    public static class DialogFlagment extends DialogFragment implements  geoName {
        String select;
        public DialogFlagment(){
            select="";
        }
        @Override
        public Dialog onCreateDialog(Bundle savedInstanceState) {
            AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());
            builder.setTitle(R.string.locationSearch)
                    .setItems(R.array.locallist, new DialogInterface.OnClickListener() {
                        public void onClick(DialogInterface dialog, int which) {
                            // The 'which' argument contains the index position
                            // of the selected item
                            select =  Fullgeo[which];

                        }
                    });
            return builder.create();
        }
        public String getSelect(){
            return  select;
        }
    }

}
