/**
 * QuantityConversions.c
 *
 * CreatorZ
 * © 2021 DayZ CreatorZ Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class QuantityConversions
{
	override static int HasItemQuantity( notnull EntityAI item )
	{
		if ( item.IsInherited( InventoryItem ) )
		{
			if ( item.IsInherited( Magazine) )
			{
				//return QUANTITY_PROGRESS;
				if( item.ConfigIsExisting( "iconCartridge" ))
				{
					return QUANTITY_COUNT;
				}
				else
				{
					return QUANTITY_PROGRESS;
				}
			}
			
			bool show_quantity = item.ConfigGetBool("quantityShow");
			if(!show_quantity)
			{
				return QUANTITY_HIDDEN;
			}
			
			int max = item.ConfigGetInt("varQuantityMax");
			bool bar = item.ConfigGetBool("quantityBar");
			if ( max > 0 )
			{
				if ( bar )
				{
					return QUANTITY_PROGRESS;
				}
				else
				{
					return QUANTITY_COUNT;
				}
			}
		}
		return QUANTITY_HIDDEN;
	}	
}