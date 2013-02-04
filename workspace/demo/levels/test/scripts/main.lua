local engine = Engine:GetInstance()
local levelSystem = engine:GetLevelSystem()

local entity = levelSystem:GetEntity(0)
local component = entity:GetComponentAt(0)

io.write("Component: ", Component:TypeToString(component:GetType()))

local i = 0
while engine:GetAppState() == "Running" do
	Sleep() -- Allow Engine Update
end