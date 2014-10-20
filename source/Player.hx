package ;

import flixel.FlxSprite;
import flixel.FlxG;
import flixel.FlxObject;

class Player extends FlxSprite 
{
	private var GRAVITY:Int = 980;
	private var MAX_SPEED:Int = 200;
	private var MAX_JUMP:Float;
	private var DRAG = 600;
	private var ACCELERATION:Int = 600;
	private var hasDoubleJumped:Bool = false;
	
	public function new(X:Float=0, Y:Float=0) {
		super(X,Y);
		
		MAX_JUMP = GRAVITY / 3;

		loadGraphic("assets/images/player.png", true, 32, 32);
		
		setFacingFlip(FlxObject.LEFT, false, false);
		setFacingFlip(FlxObject.RIGHT, true, false);
			
		animation.add("run", [3, 4, 5], 6, false);
		animation.add("jump", [0], 6, false);
		animation.add("idle", [3], 6, false);
		this.drag.x = DRAG;

		this.acceleration.y = GRAVITY;
		this.maxVelocity.x = MAX_SPEED;
		this.maxVelocity.y = MAX_JUMP;
	}

	private function movement():Void
	{
		if(FlxG.keys.pressed.A) {
			this.acceleration.x = -ACCELERATION;
			facing = FlxObject.RIGHT;
		}else if(FlxG.keys.pressed.D) {
			this.acceleration.x = ACCELERATION;

			facing = FlxObject.LEFT;
		}else {
			this.acceleration.x = 0;
		}

		if(FlxG.keys.pressed.W && this.isTouching(FlxObject.FLOOR)) {
		
			this.velocity.y = -ACCELERATION;
			facing = FlxObject.UP;
		
		} else if(FlxG.keys.pressed.W && !this.isTouching(FlxObject.FLOOR) 
					&& !hasDoubleJumped && (this.velocity.y >= -MAX_JUMP / 1.5 && this.velocity.y <= MAX_JUMP / 1.5)) {
			
			hasDoubleJumped = true;
			this.maxVelocity.y = MAX_JUMP*2;
			this.velocity.y = -ACCELERATION;
			this.maxVelocity.y = MAX_JUMP;

		} else if(this.isTouching(FlxObject.FLOOR)){
			hasDoubleJumped = false;
		}
		
	}
	private function animationCheck():Void
	{
		if(velocity.x != 0 && velocity.y == 0 || velocity.y != 0)
	    {
			switch(facing)
			{
				case FlxObject.LEFT, FlxObject.RIGHT:
					animation.play("run");
				case FlxObject.UP:
					animation.play("jump");
			}
		}else {
			animation.play("idle");
		}
	}
	override public function update():Void
	{
		movement();
		animationCheck();

		super.update();
	}

}
