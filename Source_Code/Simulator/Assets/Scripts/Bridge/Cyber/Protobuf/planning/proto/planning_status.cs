// This file was generated by a tool; you should avoid making direct changes.
// Consider using 'partial classes' to extend these types
// Input: planning_status.proto

#pragma warning disable 0612, 1591, 3021
namespace apollo.planning
{

    [global::ProtoBuf.ProtoContract()]
    public partial class BareIntersectionStatus : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public BareIntersectionStatus()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue("")]
        public string current_pnc_junction_overlap_id
        {
            get { return __pbn__current_pnc_junction_overlap_id ?? ""; }
            set { __pbn__current_pnc_junction_overlap_id = value; }
        }
        public bool ShouldSerializecurrent_pnc_junction_overlap_id()
        {
            return __pbn__current_pnc_junction_overlap_id != null;
        }
        public void Resetcurrent_pnc_junction_overlap_id()
        {
            __pbn__current_pnc_junction_overlap_id = null;
        }
        private string __pbn__current_pnc_junction_overlap_id;

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue("")]
        public string done_pnc_junction_overlap_id
        {
            get { return __pbn__done_pnc_junction_overlap_id ?? ""; }
            set { __pbn__done_pnc_junction_overlap_id = value; }
        }
        public bool ShouldSerializedone_pnc_junction_overlap_id()
        {
            return __pbn__done_pnc_junction_overlap_id != null;
        }
        public void Resetdone_pnc_junction_overlap_id()
        {
            __pbn__done_pnc_junction_overlap_id = null;
        }
        private string __pbn__done_pnc_junction_overlap_id;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class ChangeLaneStatus : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public ChangeLaneStatus()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue(Status.InChangeLane)]
        public Status status
        {
            get { return __pbn__status ?? Status.InChangeLane; }
            set { __pbn__status = value; }
        }
        public bool ShouldSerializestatus()
        {
            return __pbn__status != null;
        }
        public void Resetstatus()
        {
            __pbn__status = null;
        }
        private Status? __pbn__status;

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue("")]
        public string path_id
        {
            get { return __pbn__path_id ?? ""; }
            set { __pbn__path_id = value; }
        }
        public bool ShouldSerializepath_id()
        {
            return __pbn__path_id != null;
        }
        public void Resetpath_id()
        {
            __pbn__path_id = null;
        }
        private string __pbn__path_id;

        [global::ProtoBuf.ProtoMember(3)]
        public double timestamp
        {
            get { return __pbn__timestamp.GetValueOrDefault(); }
            set { __pbn__timestamp = value; }
        }
        public bool ShouldSerializetimestamp()
        {
            return __pbn__timestamp != null;
        }
        public void Resettimestamp()
        {
            __pbn__timestamp = null;
        }
        private double? __pbn__timestamp;

        [global::ProtoBuf.ProtoContract()]
        public enum Status
        {
            [global::ProtoBuf.ProtoEnum(Name = @"IN_CHANGE_LANE")]
            InChangeLane = 1,
            [global::ProtoBuf.ProtoEnum(Name = @"CHANGE_LANE_FAILED")]
            ChangeLaneFailed = 2,
            [global::ProtoBuf.ProtoEnum(Name = @"CHANGE_LANE_SUCCESS")]
            ChangeLaneSuccess = 3,
        }

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class StopTime : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public StopTime()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue("")]
        public string obstacle_id
        {
            get { return __pbn__obstacle_id ?? ""; }
            set { __pbn__obstacle_id = value; }
        }
        public bool ShouldSerializeobstacle_id()
        {
            return __pbn__obstacle_id != null;
        }
        public void Resetobstacle_id()
        {
            __pbn__obstacle_id = null;
        }
        private string __pbn__obstacle_id;

        [global::ProtoBuf.ProtoMember(2)]
        public double obstacle_stop_timestamp
        {
            get { return __pbn__obstacle_stop_timestamp.GetValueOrDefault(); }
            set { __pbn__obstacle_stop_timestamp = value; }
        }
        public bool ShouldSerializeobstacle_stop_timestamp()
        {
            return __pbn__obstacle_stop_timestamp != null;
        }
        public void Resetobstacle_stop_timestamp()
        {
            __pbn__obstacle_stop_timestamp = null;
        }
        private double? __pbn__obstacle_stop_timestamp;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class CrosswalkStatus : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public CrosswalkStatus()
        {
            stop_time = new global::System.Collections.Generic.List<StopTime>();
            finished_crosswalk = new global::System.Collections.Generic.List<string>();
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue("")]
        public string crosswalk_id
        {
            get { return __pbn__crosswalk_id ?? ""; }
            set { __pbn__crosswalk_id = value; }
        }
        public bool ShouldSerializecrosswalk_id()
        {
            return __pbn__crosswalk_id != null;
        }
        public void Resetcrosswalk_id()
        {
            __pbn__crosswalk_id = null;
        }
        private string __pbn__crosswalk_id;

        [global::ProtoBuf.ProtoMember(2)]
        public global::System.Collections.Generic.List<StopTime> stop_time { get; private set; }

        [global::ProtoBuf.ProtoMember(3)]
        public global::System.Collections.Generic.List<string> finished_crosswalk { get; private set; }

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class DestinationStatus : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public DestinationStatus()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue(false)]
        public bool has_passed_destination
        {
            get { return __pbn__has_passed_destination ?? false; }
            set { __pbn__has_passed_destination = value; }
        }
        public bool ShouldSerializehas_passed_destination()
        {
            return __pbn__has_passed_destination != null;
        }
        public void Resethas_passed_destination()
        {
            __pbn__has_passed_destination = null;
        }
        private bool? __pbn__has_passed_destination;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class PedestrianStatus : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public PedestrianStatus()
        {
            stop_time = new global::System.Collections.Generic.List<StopTime>();
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public global::System.Collections.Generic.List<StopTime> stop_time { get; private set; }

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class PullOverStatus : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public PullOverStatus()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue(false)]
        public bool is_feasible
        {
            get { return __pbn__is_feasible ?? false; }
            set { __pbn__is_feasible = value; }
        }
        public bool ShouldSerializeis_feasible()
        {
            return __pbn__is_feasible != null;
        }
        public void Resetis_feasible()
        {
            __pbn__is_feasible = null;
        }
        private bool? __pbn__is_feasible;

        [global::ProtoBuf.ProtoMember(2)]
        public global::apollo.common.PointENU position { get; set; }

        [global::ProtoBuf.ProtoMember(3)]
        public double theta
        {
            get { return __pbn__theta.GetValueOrDefault(); }
            set { __pbn__theta = value; }
        }
        public bool ShouldSerializetheta()
        {
            return __pbn__theta != null;
        }
        public void Resettheta()
        {
            __pbn__theta = null;
        }
        private double? __pbn__theta;

        [global::ProtoBuf.ProtoMember(4)]
        public double length_front
        {
            get { return __pbn__length_front.GetValueOrDefault(); }
            set { __pbn__length_front = value; }
        }
        public bool ShouldSerializelength_front()
        {
            return __pbn__length_front != null;
        }
        public void Resetlength_front()
        {
            __pbn__length_front = null;
        }
        private double? __pbn__length_front;

        [global::ProtoBuf.ProtoMember(5)]
        public double length_back
        {
            get { return __pbn__length_back.GetValueOrDefault(); }
            set { __pbn__length_back = value; }
        }
        public bool ShouldSerializelength_back()
        {
            return __pbn__length_back != null;
        }
        public void Resetlength_back()
        {
            __pbn__length_back = null;
        }
        private double? __pbn__length_back;

        [global::ProtoBuf.ProtoMember(6)]
        public double width_left
        {
            get { return __pbn__width_left.GetValueOrDefault(); }
            set { __pbn__width_left = value; }
        }
        public bool ShouldSerializewidth_left()
        {
            return __pbn__width_left != null;
        }
        public void Resetwidth_left()
        {
            __pbn__width_left = null;
        }
        private double? __pbn__width_left;

        [global::ProtoBuf.ProtoMember(7)]
        public double width_right
        {
            get { return __pbn__width_right.GetValueOrDefault(); }
            set { __pbn__width_right = value; }
        }
        public bool ShouldSerializewidth_right()
        {
            return __pbn__width_right != null;
        }
        public void Resetwidth_right()
        {
            __pbn__width_right = null;
        }
        private double? __pbn__width_right;

        [global::ProtoBuf.ProtoMember(8)]
        public int idx
        {
            get { return __pbn__idx.GetValueOrDefault(); }
            set { __pbn__idx = value; }
        }
        public bool ShouldSerializeidx()
        {
            return __pbn__idx != null;
        }
        public void Resetidx()
        {
            __pbn__idx = null;
        }
        private int? __pbn__idx;

        [global::ProtoBuf.ProtoMember(9)]
        [global::System.ComponentModel.DefaultValue(false)]
        public bool is_in_pull_over_scenario
        {
            get { return __pbn__is_in_pull_over_scenario ?? false; }
            set { __pbn__is_in_pull_over_scenario = value; }
        }
        public bool ShouldSerializeis_in_pull_over_scenario()
        {
            return __pbn__is_in_pull_over_scenario != null;
        }
        public void Resetis_in_pull_over_scenario()
        {
            __pbn__is_in_pull_over_scenario = null;
        }
        private bool? __pbn__is_in_pull_over_scenario;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class ReroutingStatus : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public ReroutingStatus()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public double last_rerouting_time
        {
            get { return __pbn__last_rerouting_time.GetValueOrDefault(); }
            set { __pbn__last_rerouting_time = value; }
        }
        public bool ShouldSerializelast_rerouting_time()
        {
            return __pbn__last_rerouting_time != null;
        }
        public void Resetlast_rerouting_time()
        {
            __pbn__last_rerouting_time = null;
        }
        private double? __pbn__last_rerouting_time;

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue(false)]
        public bool need_rerouting
        {
            get { return __pbn__need_rerouting ?? false; }
            set { __pbn__need_rerouting = value; }
        }
        public bool ShouldSerializeneed_rerouting()
        {
            return __pbn__need_rerouting != null;
        }
        public void Resetneed_rerouting()
        {
            __pbn__need_rerouting = null;
        }
        private bool? __pbn__need_rerouting;

        [global::ProtoBuf.ProtoMember(3)]
        public global::apollo.routing.RoutingRequest routing_request { get; set; }

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class RightOfWayStatus : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public RightOfWayStatus()
        {
            junction = new global::System.Collections.Generic.Dictionary<string, bool>();
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::ProtoBuf.ProtoMap]
        public global::System.Collections.Generic.Dictionary<string, bool> junction { get; private set; }

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class ScenarioStatus : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public ScenarioStatus()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue(ScenarioConfig.ScenarioType.LaneFollow)]
        public ScenarioConfig.ScenarioType scenario_type
        {
            get { return __pbn__scenario_type ?? ScenarioConfig.ScenarioType.LaneFollow; }
            set { __pbn__scenario_type = value; }
        }
        public bool ShouldSerializescenario_type()
        {
            return __pbn__scenario_type != null;
        }
        public void Resetscenario_type()
        {
            __pbn__scenario_type = null;
        }
        private ScenarioConfig.ScenarioType? __pbn__scenario_type;

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue(ScenarioConfig.StageType.NoStage)]
        public ScenarioConfig.StageType stage_type
        {
            get { return __pbn__stage_type ?? ScenarioConfig.StageType.NoStage; }
            set { __pbn__stage_type = value; }
        }
        public bool ShouldSerializestage_type()
        {
            return __pbn__stage_type != null;
        }
        public void Resetstage_type()
        {
            __pbn__stage_type = null;
        }
        private ScenarioConfig.StageType? __pbn__stage_type;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class SidePassStatus : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public SidePassStatus()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue("")]
        public string front_blocking_obstacle_id
        {
            get { return __pbn__front_blocking_obstacle_id ?? ""; }
            set { __pbn__front_blocking_obstacle_id = value; }
        }
        public bool ShouldSerializefront_blocking_obstacle_id()
        {
            return __pbn__front_blocking_obstacle_id != null;
        }
        public void Resetfront_blocking_obstacle_id()
        {
            __pbn__front_blocking_obstacle_id = null;
        }
        private string __pbn__front_blocking_obstacle_id;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class StopSignStatus : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public StopSignStatus()
        {
            wait_for_obstacle_id = new global::System.Collections.Generic.List<string>();
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue("")]
        public string current_stop_sign_overlap_id
        {
            get { return __pbn__current_stop_sign_overlap_id ?? ""; }
            set { __pbn__current_stop_sign_overlap_id = value; }
        }
        public bool ShouldSerializecurrent_stop_sign_overlap_id()
        {
            return __pbn__current_stop_sign_overlap_id != null;
        }
        public void Resetcurrent_stop_sign_overlap_id()
        {
            __pbn__current_stop_sign_overlap_id = null;
        }
        private string __pbn__current_stop_sign_overlap_id;

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue("")]
        public string done_stop_sign_overlap_id
        {
            get { return __pbn__done_stop_sign_overlap_id ?? ""; }
            set { __pbn__done_stop_sign_overlap_id = value; }
        }
        public bool ShouldSerializedone_stop_sign_overlap_id()
        {
            return __pbn__done_stop_sign_overlap_id != null;
        }
        public void Resetdone_stop_sign_overlap_id()
        {
            __pbn__done_stop_sign_overlap_id = null;
        }
        private string __pbn__done_stop_sign_overlap_id;

        [global::ProtoBuf.ProtoMember(3)]
        public global::System.Collections.Generic.List<string> wait_for_obstacle_id { get; private set; }

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class TrafficLightStatus : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public TrafficLightStatus()
        {
            current_traffic_light_overlap_id = new global::System.Collections.Generic.List<string>();
            done_traffic_light_overlap_id = new global::System.Collections.Generic.List<string>();
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public global::System.Collections.Generic.List<string> current_traffic_light_overlap_id { get; private set; }

        [global::ProtoBuf.ProtoMember(2)]
        public global::System.Collections.Generic.List<string> done_traffic_light_overlap_id { get; private set; }

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class SidePassStopStatus : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public SidePassStopStatus()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public global::apollo.common.PathPoint change_lane_stop_path_point { get; set; }

        [global::ProtoBuf.ProtoMember(2)]
        public bool check_clear_flag
        {
            get { return __pbn__check_clear_flag.GetValueOrDefault(); }
            set { __pbn__check_clear_flag = value; }
        }
        public bool ShouldSerializecheck_clear_flag()
        {
            return __pbn__check_clear_flag != null;
        }
        public void Resetcheck_clear_flag()
        {
            __pbn__check_clear_flag = null;
        }
        private bool? __pbn__check_clear_flag;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class PlanningStatus : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public PlanningStatus()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public BareIntersectionStatus bare_intersection { get; set; }

        [global::ProtoBuf.ProtoMember(2)]
        public ChangeLaneStatus change_lane { get; set; }

        [global::ProtoBuf.ProtoMember(3)]
        public CrosswalkStatus crosswalk { get; set; }

        [global::ProtoBuf.ProtoMember(4)]
        public DestinationStatus destination { get; set; }

        [global::ProtoBuf.ProtoMember(5)]
        public global::apollo.common.EngageAdvice engage_advice { get; set; }

        [global::ProtoBuf.ProtoMember(6)]
        public PedestrianStatus pedestrian { get; set; }

        [global::ProtoBuf.ProtoMember(7)]
        public PullOverStatus pull_over { get; set; }

        [global::ProtoBuf.ProtoMember(8)]
        public ReroutingStatus rerouting { get; set; }

        [global::ProtoBuf.ProtoMember(9)]
        public RightOfWayStatus right_of_way { get; set; }

        [global::ProtoBuf.ProtoMember(10)]
        public ScenarioStatus scenario { get; set; }

        [global::ProtoBuf.ProtoMember(11)]
        public SidePassStatus side_pass { get; set; }

        [global::ProtoBuf.ProtoMember(12)]
        public StopSignStatus stop_sign { get; set; }

        [global::ProtoBuf.ProtoMember(13)]
        public TrafficLightStatus traffic_light { get; set; }

        [global::ProtoBuf.ProtoMember(14)]
        public SidePassStopStatus side_pass_stop { get; set; }

    }

}

#pragma warning restore 0612, 1591, 3021
