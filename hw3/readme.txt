ID number:406410076
Name:温彥博
Environment(哪一台工作站):csie2.cs.ccu.edu.tw
Email:f12angelo@gmail.com
Simple Guide:
    1.兩種方式建立日期(月/日/年)
    Date d1; // initializes to Jan 1, 2000
    Date d2 (3, 4, 1992);
    2.能讓者用鍵盤輸入日期(月/日/年)
    void Input()
    3.可以顯示日期
    void Show()
    4.根據參數設定日期顯示格式
    bool SetFormat(char f)
    5.根據參數設定日期，如果輸入格式錯誤回傳false，維持原本日期
    bool Set(int m, int d, int y)
    6.分別會回傳月、日、年
    int GetMonth()、int GetDay()、int GetYear()
    7.根據參數增加天數，預設為一天
    Date d1(10, 31, 1998); // Oct 31, 1998
    Date d2(6, 29, 1950); // June 29, 1950
    d1.Increment(); // d1 is now Nov 1, 1998
    d2.Increment(5); // d2 is now July 4, 1950
    8.日期比較功能:
    如果calling object日期比較早回傳-1，如果calling object日期比較晚回傳1，兩者相同回傳0

    按照以上功能製造了一個class ，並在main中測試功能