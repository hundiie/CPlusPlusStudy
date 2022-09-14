
public class Test
{
    //각각 레코드 선언
    record TransactionPosion
    {
        public int HP { get; init; }
        public string Mask { get; init; }
    }
    record TransactionMedicine
    {
        public int HP { get; init; }
        public int Magic { get; init; }
        public int RunSpeed { get; init; }

        public override string ToString()
        {
            return $"{HP}, {Magic}, {RunSpeed}";
        }
    }

    class MainApp
    {
        static void Main()
        {
            //실행용 메인
            Posion();
            Medicine();
        }
        static void Posion()
        {
            // Posion1에 값을 넣음
            TransactionPosion Posion1 = new TransactionPosion { HP = 100, Mask = "귀여워짐" };
            // Posion1값을 with를 써서 Posion2에 복사하고 달라지는 부분만 {}에 적음(3도 마찬가지)
            TransactionPosion Posion2 = Posion1 with { Mask = "험악해짐" };
            TransactionPosion Posion3 = Posion2 with { Mask = "괴랄해짐" };
        }
        static void Medicine()
        {
            // Medicine1에 값을 넣음
            TransactionMedicine Medicine1 = new(){HP = 10, Magic = 50, RunSpeed = 2 };
            // Medicine1값을 with를 써서 Medicine2에 복사하고 달라지는 부분만 {}에 적음(3도 마찬가지)
            TransactionMedicine Medicine2 = Medicine1 with { Magic = 100 };
            TransactionMedicine Medicine3 = Medicine1 with { HP = 50 };
        }
    }
}