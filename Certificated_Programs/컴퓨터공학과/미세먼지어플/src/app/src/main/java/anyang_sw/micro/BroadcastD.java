/*
    미세먼지 알림 프로그램
    알림
    작성자 : 조상호, 유성근

    작성일 : 2018.12.07

    구조 ; 이 프로그램은 다음과 같은 클래스로 구성되어있음
            BroadcastD : 알림에 대한 request 클래스
                    메소드
                    onReceive : 알림시간에 호출되는 메소드


    공유 변수
        MainActivity 클래스
                int sPM10 : 알람에 전달하는 미세먼지 값 저장. 범위 : 0 ~ 500
                String sLocation : 알림에 전달하는 지역 값 : 범위 "" 또는 위치값
                String sDate : 알림에 전달하는 시간에 대한 값 : 범위 "" 또는 "(시):(분)"
 */

package anyang_sw.micro;


import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

class BroadcastD extends BroadcastReceiver {

    public static String ID = "0";
    @Override
    public void onReceive(Context context, Intent intent) {

        NotificationManager notificationmanager = (NotificationManager) context.getSystemService(Context.NOTIFICATION_SERVICE);
        PendingIntent pendingIntent = PendingIntent.getActivity(context, 0, new Intent(context, MainActivity.class), PendingIntent.FLAG_UPDATE_CURRENT);
        Notification.Builder builder = new Notification.Builder(context);

        int pm = MainActivity.sPM10;
        String s = MainActivity.sLocation;
        String d = MainActivity.sDate;

        String title = s + " " + d + " 미세먼지 농도 : ";
        String content = "";
        int icon;

        if (pm <= 15) {
            icon = R.drawable.good;
            title = title + "좋음";
            content = "미세먼지 걱정 없는 하루!";
        } else if (pm <= 35) {
            icon = R.drawable.fine;
            title = title + "보통";
            content = "실외활동 시 특별히 행동에 제약을 받을 필요는 없지만 몸 상태에 따라 유의하여 활동하시기 바랍니다.";
        } else if (pm <= 75) {
            icon = R.drawable.warning;
            title = title + "나쁨";
            content = "마스크 착용 권고, 어린이와 노인, 호흡기 질환자 등은 외출을 자제, 장시간 또는 무리한 실외활동 제한하며, 특히 눈이 아픈 증상이 있거나 기침이나 목의 통증으로 불편한 사람은 실외활동을 피해야 합니다.";
        } else {
            icon = R.drawable.bad;
            title = title + "매우나쁨";
            content = "마스크 착용 권고, 어린이와 노인, 호흡기 질환자 등은 외출을 자제, 장시간 또는 무리한 실외활동 제한, 목의 통증과 기침 등의 증상이 있는 사람은 실외활동을 피해야 합니다.";
        }


        builder.setSmallIcon(icon).setTicker("미세먼지").setWhen(System.currentTimeMillis())
                .setNumber(1).setContentTitle(title).setContentText(content)
                .setDefaults(Notification.DEFAULT_SOUND | Notification.DEFAULT_VIBRATE).setContentIntent(pendingIntent).setAutoCancel(true);

//setSmallIcon - > 작은 아이콘 이미지
//setTicker - > 알람이 출력될 때 상단에 나오는 문구.
//setWhen -> 알림 출력 시간.
//setContentTitle-> 알림 제목
//setConentText->푸쉬내용

        notificationmanager.notify(1, builder.build());
    }


}