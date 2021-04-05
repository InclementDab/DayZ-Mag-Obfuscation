/**
 * InspectMenuNew.c
 *
 * CreatorZ
 * © 2021 DayZ CreatorZ Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class InspectMenuNew extends UIScriptedMenu
{
	override static void UpdateItemInfoQuantity(Widget root_widget, EntityAI item)
	{
		if ( item.IsInherited( ZombieBase ) || item.IsInherited( Car ) ) return;
		
		ItemBase item_base = ItemBase.Cast( item );
		if( item_base )
		{
			float item_quantity = item_base.GetQuantity();
			int max_quantity = item.GetQuantityMax();
			
			float quantity_ratio;
			
			if( max_quantity > 0 ) // Some items, like books, have max_quantity set to 0 => division by ZERO error in quantity_ratio
			{
				string quantity_str;
				if( item.ConfigGetString("stackedUnit") == "pc." )
				{
					if( item_quantity == 1 )
					{
						WidgetTrySetText( root_widget, "ItemQuantityWidget", item_quantity.ToString() + " " + "#inv_inspect_piece", Colors.COLOR_DEFAULT );
					}
					else
					{
						WidgetTrySetText( root_widget, "ItemQuantityWidget", item_quantity.ToString() + " " + "#inv_inspect_pieces", Colors.COLOR_DEFAULT );
					}		
				}
				else if( item.ConfigGetString("stackedUnit") == "percentage" )
				{
					quantity_ratio = Math.Round( ( item_quantity / max_quantity ) * 100 );
					
					quantity_str = "#inv_inspect_remaining " + quantity_ratio.ToString() + "#inv_inspect_percent";
					WidgetTrySetText( root_widget, "ItemQuantityWidget", quantity_str, Colors.COLOR_DEFAULT );			
				}
				else if( item.ConfigGetString("stackedUnit") == "g" )
				{
					quantity_ratio = Math.Round( ( item_quantity / max_quantity ) * 100 );
					
					quantity_str = "#inv_inspect_remaining " + quantity_ratio.ToString() + "#inv_inspect_percent";
					WidgetTrySetText( root_widget, "ItemQuantityWidget", quantity_str, Colors.COLOR_DEFAULT );			
				}
				else if( item.ConfigGetString("stackedUnit") == "ml" )
				{
					quantity_ratio = Math.Round( ( item_quantity / max_quantity ) * 100 );
					
					quantity_str = "#inv_inspect_remaining " + quantity_ratio.ToString() + "#inv_inspect_percent";
					WidgetTrySetText( root_widget, "ItemQuantityWidget", quantity_str, Colors.COLOR_DEFAULT );
				}
				else if( item.IsInherited( Magazine ) )
				{
					Magazine magazine_item;
					Class.CastTo(magazine_item, item);
					
					if( magazine_item.GetAmmoCount() == 1 )
					{
						WidgetTrySetText( root_widget, "ItemQuantityWidget", "" );
					}
					else
					{
						WidgetTrySetText( root_widget, "ItemQuantityWidget", "" );
					}
				}
				else
				{
					WidgetTrySetText( root_widget, "ItemQuantityWidget", "" );
				}
			}
			else
			{
				if ( item.IsInherited( ClothingBase ) )
				{
					float heatIsolation = MiscGameplayFunctions.GetCurrentItemHeatIsolation( item_base );
					if ( heatIsolation <= GameConstants.HEATISO_THRESHOLD_BAD )
					{
						WidgetTrySetText( root_widget, "ItemQuantityWidget", "#inv_inspect_iso_bad", GetTemperatureColor( 10 ) );
					}
					else if ( ( heatIsolation > GameConstants.HEATISO_THRESHOLD_BAD ) && ( heatIsolation <= GameConstants.HEATISO_THRESHOLD_LOW ) )
					{
						WidgetTrySetText( root_widget, "ItemQuantityWidget", "#inv_inspect_iso_low", GetTemperatureColor( 20 ) );
					}
					else if ( ( heatIsolation > GameConstants.HEATISO_THRESHOLD_LOW ) && ( heatIsolation <= GameConstants.HEATISO_THRESHOLD_MEDIUM ) )
					{
						WidgetTrySetText( root_widget, "ItemQuantityWidget", "#inv_inspect_iso_medium", GetTemperatureColor( 30 ) );
					}
					else if ( ( heatIsolation > GameConstants.HEATISO_THRESHOLD_MEDIUM ) && ( heatIsolation <= GameConstants.HEATISO_THRESHOLD_HIGH ) )
					{
						WidgetTrySetText( root_widget, "ItemQuantityWidget", "#inv_inspect_iso_high", GetTemperatureColor( 50 ) );
					}
					else
					{
						WidgetTrySetText( root_widget, "ItemQuantityWidget", "#inv_inspect_iso_excel", GetTemperatureColor( 70 ) );
					}
				}
				else
				{
					WidgetTrySetText( root_widget, "ItemQuantityWidget", "" );
				}
			}
		}
	}
}