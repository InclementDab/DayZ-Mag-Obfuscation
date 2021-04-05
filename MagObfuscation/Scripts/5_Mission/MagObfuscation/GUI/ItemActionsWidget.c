/**
 * ItemActionsWidget.c
 *
 * CreatorZ
 * © 2021 DayZ CreatorZ Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class ItemActionsWidget extends ScriptedWidgetEventHandler
{
	protected override void SetWeaponQuantity(int chamber, int mag, string itemWidget, string quantityPBWidget, string quantityTextWidget, bool enabled)
	{		
		Widget widget = m_Root.FindAnyWidget(itemWidget);
		if (!enabled) {
			widget.Show(false);
			return;
		}
		
		string wpn_qty = "";

		ProgressBarWidget progressBar;
		TextWidget textWidget;
		Class.CastTo(progressBar, widget.FindAnyWidget(quantityPBWidget));
		Class.CastTo(textWidget, widget.FindAnyWidget(quantityTextWidget));
		widget.Show(false);
		
		Weapon_Base wpn;
		Magazine maga;
		int mag_quantity = -1;

		if (!Class.CastTo(wpn, m_EntityInHands)) {
			return;
		}
		
		progressBar.Show(false);
			
		// Magnum edge case
		if (Magnum.Cast(wpn)) {
			
			mag_quantity = 0;
			for (int j = 0; j < wpn.GetMuzzleCount(); j++) {
				if (wpn.IsChamberFull(j) && !wpn.IsChamberFiredOut(j)) {
					mag_quantity++; 
				}
			}
						
			textWidget.SetText(mag_quantity.ToString());
			return;
		}
		
		for (int i = 0; i < wpn.GetMuzzleCount(); i++) {
			if (i > 0 && (wpn.GetMuzzleCount() < 3 || i%2 == 0)) {
				wpn_qty += " ";
			}
			
			if (wpn.IsChamberEmpty(i)) {
				wpn_qty += "-";
			}
			else if (wpn.IsChamberFiredOut(i)) {
				wpn_qty += "F";
			}
			else {
				wpn_qty += "+";
			}		
		}
	
		if (wpn.IsJammed()) {
			wpn_qty = "X";
		}
		
		textWidget.SetText(wpn_qty);
		textWidget.Show(true);
		textWidget.GetParent().Show(true);
	}
}