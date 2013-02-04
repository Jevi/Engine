local engine = Engine:GetInstance()
local levelSystem = engine:GetLevelSystem()

local i = 0
while engine:GetAppState() == "Running" do
	local entity = levelSystem:GetEntity(0)
	io.write("X: ", entity:GetX(), "Y: ", entity:GetY(), "\n")
	Sleep() -- Allow Engine Update
end

function MoveEntity()
	
end