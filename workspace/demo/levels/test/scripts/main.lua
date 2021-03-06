engine = myEngine:GetInstance()
levelSystem = engine:GetLevelSystem()

right = true

function Update()
	for i=0,levelSystem:GetNumEntity() - 1 do
		entity = levelSystem:GetEntityAt(i)
		if myMath:MetersToPixels(entity.bodyDef.position.x) > engine:GetAppWidth() then
			right = false
		elseif myMath:MetersToPixels(entity.bodyDef.position.x) < 0 then
			right = true
		end

		if right then
			entity.bodyDef.angle = entity.bodyDef.angle + myMath:DegreesToRadians(math.random(5,10))
			entity.bodyDef.position.x = entity.bodyDef.position.x + myMath:PixelsToMeters(math.random(3,5))
			-- entity.scale.x = entity.scale.x + math.random()
			-- entity.scale.y = entity.scale.y + math.random()
		else
			entity.bodyDef.angle = entity.bodyDef.angle - myMath:DegreesToRadians(math.random(5,10))
			entity.bodyDef.position.x = entity.bodyDef.position.x - myMath:PixelsToMeters(math.random(3,5))
			-- entity.scale.x = entity.scale.x - math.random()
			-- entity.scale.y = entity.scale.y - math.random()
		end
	end
end

function Render()
end

while engine:GetAppState() == "Running" do
	Update()
	Render()
	Sleep()
end