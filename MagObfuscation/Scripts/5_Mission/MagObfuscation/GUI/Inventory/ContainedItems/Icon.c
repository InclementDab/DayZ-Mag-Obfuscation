modded class Icon
{
	override void CheckIsWeapon()
	{		
		Weapon_Base wpn = Weapon_Base.Cast( m_Obj );
		if( wpn )
		{
			m_AmmoIcons = new array<ImageWidget>;
			m_IsWeapon = true;
			float x_pos = 0.0;
			float widht = 0.0, height = 0.0; 
		}
		else
		{
			m_IsWeapon = false;
		}	
	}
}