package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;
import flixel.tile.FlxTilemap;
import flixel.util.FlxStringUtil;
import flixel.FlxObject;
import flixel.FlxCamera;
import flixel.addons.editors.ogmo.FlxOgmoLoader;
/**
 * A FlxState which can be used for the actual gameplay.
 */
class PlayState extends FlxState
{
	var level:FlxOgmoLoader;
	var levelWalls:FlxTilemap;
	var player:Player;

	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{
		level = new FlxOgmoLoader("assets/data/room-001.oel");
		
		levelWalls = level.loadTilemap("assets/images/tiles.png", 16, 16, "walls");
		levelWalls.setTileProperties(1, FlxObject.NONE);
		levelWalls.setTileProperties(2, FlxObject.ANY);
		add(levelWalls);

		player = new Player(20, 20);
		
		level.loadEntities(placeEntities, "entities");
		FlxG.camera.follow(player, FlxCamera.STYLE_PLATFORMER, 1);
		add(player);
		FlxG.mouse.visible = false;
		super.create();
	}
	
	/**
	 * Function that is called when this state is destroyed - you might want to 
	 * consider setting all objects this state uses to null to help garbage collection.
	 */
	override public function destroy():Void
	{
		super.destroy();
	}

	/**
	 * Function that is called once every frame.
	 */
	override public function update():Void
	{
		FlxG.collide(player, levelWalls);

		super.update();
	}

	private function placeEntities(entityName:String, entityData:Xml):Void
	{
		if(entityName == "player")
		{
			player.x = Std.parseInt(entityData.get("x"));
			player.y = Std.parseInt(entityData.get("y"));
		}
	}
}
