using System;
using System.Drawing;

namespace Battle_City
{
    abstract class GameObject : Object
    {
        public static ObjType[,] Map { get; set; }
        public static int BlockSize = 15; // how many pixels of a block width or length
        public static GameObjectManager GOM;

        public Bitmap Img { get; set; }
        public ObjType T { get; set; }
        public int X
        {
            get => x / BlockSize;
            protected set => x = (int)value * BlockSize ;
        }
        public int Y
        {
            get => y / BlockSize;
            protected set => y = (int)value * BlockSize;
        }

        public int x; // pixel coordinate
        public int y;

        public GameObject() { }

        public abstract void Draw();
        public abstract Bitmap GetImage();
        public abstract Rectangle GetCollisionRectangle();
        public abstract void Update();
    }
}
