using Battle_City.Properties;
using System.Drawing;
using System.Media;

namespace Battle_City
{
    class Tank : MovableObejct
    {
        protected Bullet bullet;
        private static SoundPlayer fireSound = new SoundPlayer(Resources.fire);

        public Tank(int xx, int yy, double speed) : base(xx, yy, speed)
        {
            Dir = Direction.Right;
            bullet = null;
    }

        public override Bitmap GetImage()
        {
            Img = imgArr[(int)Dir];
            Img.MakeTransparent(Color.Black);
            return Img;
        }

        protected void Shoot()
        {
            if (this is TankPlayer)
            {
                fireSound.Play();
            }
            bullet = new Bullet(X, Y, Dir, this);
            GOM.CreateBullet(bullet);
        }

        public override void Update()
        {
            Draw();
            if (null != bullet)
            {
                bullet.Update();
            }
        }

        public void BulletBlast()
        {
            bullet.Destory();
            bullet = null;
        }
    }
}
