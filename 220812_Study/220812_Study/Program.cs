using System;

namespace aa
{
    class M_info
    {
        public string Name { get; set; }
        public float hp { get; set; }
        public float atk { get; set; }
        public float def { get; set; }
        public float speed { get; set; }
    }

    class Main
    {
        public M_info inpo = new M_info()
        {
            Name = "기본",
            hp = 100,
            atk = 10,
            def = 10,
            speed = 1
        };

    }
}