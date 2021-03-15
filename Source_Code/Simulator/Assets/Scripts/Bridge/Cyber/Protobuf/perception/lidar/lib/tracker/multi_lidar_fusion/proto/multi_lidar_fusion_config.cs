// This file was generated by a tool; you should avoid making direct changes.
// Consider using 'partial classes' to extend these types
// Input: multi_lidar_fusion_config.proto

#pragma warning disable 0612, 1591, 3021
namespace apollo.perception.lidar
{

    [global::ProtoBuf.ProtoContract()]
    public partial class MlfDistanceWeight : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public MlfDistanceWeight()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue("")]
        public string sensor_name_pair
        {
            get { return __pbn__sensor_name_pair ?? ""; }
            set { __pbn__sensor_name_pair = value; }
        }
        public bool ShouldSerializesensor_name_pair()
        {
            return __pbn__sensor_name_pair != null;
        }
        public void Resetsensor_name_pair()
        {
            __pbn__sensor_name_pair = null;
        }
        private string __pbn__sensor_name_pair;

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue(0f)]
        public float location_dist_weight
        {
            get { return __pbn__location_dist_weight ?? 0f; }
            set { __pbn__location_dist_weight = value; }
        }
        public bool ShouldSerializelocation_dist_weight()
        {
            return __pbn__location_dist_weight != null;
        }
        public void Resetlocation_dist_weight()
        {
            __pbn__location_dist_weight = null;
        }
        private float? __pbn__location_dist_weight;

        [global::ProtoBuf.ProtoMember(3)]
        [global::System.ComponentModel.DefaultValue(0f)]
        public float direction_dist_weight
        {
            get { return __pbn__direction_dist_weight ?? 0f; }
            set { __pbn__direction_dist_weight = value; }
        }
        public bool ShouldSerializedirection_dist_weight()
        {
            return __pbn__direction_dist_weight != null;
        }
        public void Resetdirection_dist_weight()
        {
            __pbn__direction_dist_weight = null;
        }
        private float? __pbn__direction_dist_weight;

        [global::ProtoBuf.ProtoMember(4)]
        [global::System.ComponentModel.DefaultValue(0f)]
        public float bbox_size_dist_weight
        {
            get { return __pbn__bbox_size_dist_weight ?? 0f; }
            set { __pbn__bbox_size_dist_weight = value; }
        }
        public bool ShouldSerializebbox_size_dist_weight()
        {
            return __pbn__bbox_size_dist_weight != null;
        }
        public void Resetbbox_size_dist_weight()
        {
            __pbn__bbox_size_dist_weight = null;
        }
        private float? __pbn__bbox_size_dist_weight;

        [global::ProtoBuf.ProtoMember(5)]
        [global::System.ComponentModel.DefaultValue(0f)]
        public float point_num_dist_weight
        {
            get { return __pbn__point_num_dist_weight ?? 0f; }
            set { __pbn__point_num_dist_weight = value; }
        }
        public bool ShouldSerializepoint_num_dist_weight()
        {
            return __pbn__point_num_dist_weight != null;
        }
        public void Resetpoint_num_dist_weight()
        {
            __pbn__point_num_dist_weight = null;
        }
        private float? __pbn__point_num_dist_weight;

        [global::ProtoBuf.ProtoMember(6)]
        [global::System.ComponentModel.DefaultValue(0f)]
        public float histogram_dist_weight
        {
            get { return __pbn__histogram_dist_weight ?? 0f; }
            set { __pbn__histogram_dist_weight = value; }
        }
        public bool ShouldSerializehistogram_dist_weight()
        {
            return __pbn__histogram_dist_weight != null;
        }
        public void Resethistogram_dist_weight()
        {
            __pbn__histogram_dist_weight = null;
        }
        private float? __pbn__histogram_dist_weight;

        [global::ProtoBuf.ProtoMember(7)]
        [global::System.ComponentModel.DefaultValue(0f)]
        public float centroid_shift_dist_weight
        {
            get { return __pbn__centroid_shift_dist_weight ?? 0f; }
            set { __pbn__centroid_shift_dist_weight = value; }
        }
        public bool ShouldSerializecentroid_shift_dist_weight()
        {
            return __pbn__centroid_shift_dist_weight != null;
        }
        public void Resetcentroid_shift_dist_weight()
        {
            __pbn__centroid_shift_dist_weight = null;
        }
        private float? __pbn__centroid_shift_dist_weight;

        [global::ProtoBuf.ProtoMember(8)]
        [global::System.ComponentModel.DefaultValue(0f)]
        public float bbox_iou_dist_weight
        {
            get { return __pbn__bbox_iou_dist_weight ?? 0f; }
            set { __pbn__bbox_iou_dist_weight = value; }
        }
        public bool ShouldSerializebbox_iou_dist_weight()
        {
            return __pbn__bbox_iou_dist_weight != null;
        }
        public void Resetbbox_iou_dist_weight()
        {
            __pbn__bbox_iou_dist_weight = null;
        }
        private float? __pbn__bbox_iou_dist_weight;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class MlfDistanceConfig : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public MlfDistanceConfig()
        {
            foreground_weights = new global::System.Collections.Generic.List<MlfDistanceWeight>();
            background_weights = new global::System.Collections.Generic.List<MlfDistanceWeight>();
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public global::System.Collections.Generic.List<MlfDistanceWeight> foreground_weights { get; private set; }

        [global::ProtoBuf.ProtoMember(2)]
        public global::System.Collections.Generic.List<MlfDistanceWeight> background_weights { get; private set; }

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class MlfTrackObjectMatcherConfig : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public MlfTrackObjectMatcherConfig()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue(@"MultiHmBipartiteGraphMatcher")]
        public string foreground_mathcer_method
        {
            get { return __pbn__foreground_mathcer_method ?? @"MultiHmBipartiteGraphMatcher"; }
            set { __pbn__foreground_mathcer_method = value; }
        }
        public bool ShouldSerializeforeground_mathcer_method()
        {
            return __pbn__foreground_mathcer_method != null;
        }
        public void Resetforeground_mathcer_method()
        {
            __pbn__foreground_mathcer_method = null;
        }
        private string __pbn__foreground_mathcer_method;

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue(@"GnnBipartiteGraphMatcher")]
        public string background_matcher_method
        {
            get { return __pbn__background_matcher_method ?? @"GnnBipartiteGraphMatcher"; }
            set { __pbn__background_matcher_method = value; }
        }
        public bool ShouldSerializebackground_matcher_method()
        {
            return __pbn__background_matcher_method != null;
        }
        public void Resetbackground_matcher_method()
        {
            __pbn__background_matcher_method = null;
        }
        private string __pbn__background_matcher_method;

        [global::ProtoBuf.ProtoMember(3)]
        [global::System.ComponentModel.DefaultValue(100f)]
        public float bound_value
        {
            get { return __pbn__bound_value ?? 100f; }
            set { __pbn__bound_value = value; }
        }
        public bool ShouldSerializebound_value()
        {
            return __pbn__bound_value != null;
        }
        public void Resetbound_value()
        {
            __pbn__bound_value = null;
        }
        private float? __pbn__bound_value;

        [global::ProtoBuf.ProtoMember(4)]
        [global::System.ComponentModel.DefaultValue(4f)]
        public float max_match_distance
        {
            get { return __pbn__max_match_distance ?? 4f; }
            set { __pbn__max_match_distance = value; }
        }
        public bool ShouldSerializemax_match_distance()
        {
            return __pbn__max_match_distance != null;
        }
        public void Resetmax_match_distance()
        {
            __pbn__max_match_distance = null;
        }
        private float? __pbn__max_match_distance;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class MlfTrackerConfig : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public MlfTrackerConfig()
        {
            filter_name = new global::System.Collections.Generic.List<string>();
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public global::System.Collections.Generic.List<string> filter_name { get; private set; }

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class MlfMotionFilterConfig : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public MlfMotionFilterConfig()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue(true)]
        public bool use_adaptive
        {
            get { return __pbn__use_adaptive ?? true; }
            set { __pbn__use_adaptive = value; }
        }
        public bool ShouldSerializeuse_adaptive()
        {
            return __pbn__use_adaptive != null;
        }
        public void Resetuse_adaptive()
        {
            __pbn__use_adaptive = null;
        }
        private bool? __pbn__use_adaptive;

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue(true)]
        public bool use_breakdown
        {
            get { return __pbn__use_breakdown ?? true; }
            set { __pbn__use_breakdown = value; }
        }
        public bool ShouldSerializeuse_breakdown()
        {
            return __pbn__use_breakdown != null;
        }
        public void Resetuse_breakdown()
        {
            __pbn__use_breakdown = null;
        }
        private bool? __pbn__use_breakdown;

        [global::ProtoBuf.ProtoMember(3)]
        [global::System.ComponentModel.DefaultValue(true)]
        public bool use_convergence_boostup
        {
            get { return __pbn__use_convergence_boostup ?? true; }
            set { __pbn__use_convergence_boostup = value; }
        }
        public bool ShouldSerializeuse_convergence_boostup()
        {
            return __pbn__use_convergence_boostup != null;
        }
        public void Resetuse_convergence_boostup()
        {
            __pbn__use_convergence_boostup = null;
        }
        private bool? __pbn__use_convergence_boostup;

        [global::ProtoBuf.ProtoMember(4)]
        [global::System.ComponentModel.DefaultValue(5)]
        public double init_velocity_variance
        {
            get { return __pbn__init_velocity_variance ?? 5; }
            set { __pbn__init_velocity_variance = value; }
        }
        public bool ShouldSerializeinit_velocity_variance()
        {
            return __pbn__init_velocity_variance != null;
        }
        public void Resetinit_velocity_variance()
        {
            __pbn__init_velocity_variance = null;
        }
        private double? __pbn__init_velocity_variance;

        [global::ProtoBuf.ProtoMember(5)]
        [global::System.ComponentModel.DefaultValue(10)]
        public double init_acceleration_variance
        {
            get { return __pbn__init_acceleration_variance ?? 10; }
            set { __pbn__init_acceleration_variance = value; }
        }
        public bool ShouldSerializeinit_acceleration_variance()
        {
            return __pbn__init_acceleration_variance != null;
        }
        public void Resetinit_acceleration_variance()
        {
            __pbn__init_acceleration_variance = null;
        }
        private double? __pbn__init_acceleration_variance;

        [global::ProtoBuf.ProtoMember(6)]
        [global::System.ComponentModel.DefaultValue(0.4)]
        public double measured_velocity_variance
        {
            get { return __pbn__measured_velocity_variance ?? 0.4; }
            set { __pbn__measured_velocity_variance = value; }
        }
        public bool ShouldSerializemeasured_velocity_variance()
        {
            return __pbn__measured_velocity_variance != null;
        }
        public void Resetmeasured_velocity_variance()
        {
            __pbn__measured_velocity_variance = null;
        }
        private double? __pbn__measured_velocity_variance;

        [global::ProtoBuf.ProtoMember(7)]
        [global::System.ComponentModel.DefaultValue(10)]
        public double predict_variance_per_sqrsec
        {
            get { return __pbn__predict_variance_per_sqrsec ?? 10; }
            set { __pbn__predict_variance_per_sqrsec = value; }
        }
        public bool ShouldSerializepredict_variance_per_sqrsec()
        {
            return __pbn__predict_variance_per_sqrsec != null;
        }
        public void Resetpredict_variance_per_sqrsec()
        {
            __pbn__predict_variance_per_sqrsec = null;
        }
        private double? __pbn__predict_variance_per_sqrsec;

        [global::ProtoBuf.ProtoMember(8)]
        [global::System.ComponentModel.DefaultValue(3)]
        public uint boostup_history_size_minimum
        {
            get { return __pbn__boostup_history_size_minimum ?? 3; }
            set { __pbn__boostup_history_size_minimum = value; }
        }
        public bool ShouldSerializeboostup_history_size_minimum()
        {
            return __pbn__boostup_history_size_minimum != null;
        }
        public void Resetboostup_history_size_minimum()
        {
            __pbn__boostup_history_size_minimum = null;
        }
        private uint? __pbn__boostup_history_size_minimum;

        [global::ProtoBuf.ProtoMember(9)]
        [global::System.ComponentModel.DefaultValue(6)]
        public uint boostup_history_size_maximum
        {
            get { return __pbn__boostup_history_size_maximum ?? 6; }
            set { __pbn__boostup_history_size_maximum = value; }
        }
        public bool ShouldSerializeboostup_history_size_maximum()
        {
            return __pbn__boostup_history_size_maximum != null;
        }
        public void Resetboostup_history_size_maximum()
        {
            __pbn__boostup_history_size_maximum = null;
        }
        private uint? __pbn__boostup_history_size_maximum;

        [global::ProtoBuf.ProtoMember(10)]
        [global::System.ComponentModel.DefaultValue(0.5)]
        public double converged_confidence_minimum
        {
            get { return __pbn__converged_confidence_minimum ?? 0.5; }
            set { __pbn__converged_confidence_minimum = value; }
        }
        public bool ShouldSerializeconverged_confidence_minimum()
        {
            return __pbn__converged_confidence_minimum != null;
        }
        public void Resetconverged_confidence_minimum()
        {
            __pbn__converged_confidence_minimum = null;
        }
        private double? __pbn__converged_confidence_minimum;

        [global::ProtoBuf.ProtoMember(12)]
        [global::System.ComponentModel.DefaultValue(0.1)]
        public double noise_maximum
        {
            get { return __pbn__noise_maximum ?? 0.1; }
            set { __pbn__noise_maximum = value; }
        }
        public bool ShouldSerializenoise_maximum()
        {
            return __pbn__noise_maximum != null;
        }
        public void Resetnoise_maximum()
        {
            __pbn__noise_maximum = null;
        }
        private double? __pbn__noise_maximum;

        [global::ProtoBuf.ProtoMember(13)]
        [global::System.ComponentModel.DefaultValue(40)]
        public double trust_orientation_range
        {
            get { return __pbn__trust_orientation_range ?? 40; }
            set { __pbn__trust_orientation_range = value; }
        }
        public bool ShouldSerializetrust_orientation_range()
        {
            return __pbn__trust_orientation_range != null;
        }
        public void Resettrust_orientation_range()
        {
            __pbn__trust_orientation_range = null;
        }
        private double? __pbn__trust_orientation_range;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class MlfMotionRefinerConfig : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public MlfMotionRefinerConfig()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue(10)]
        public double claping_acceleration_threshold
        {
            get { return __pbn__claping_acceleration_threshold ?? 10; }
            set { __pbn__claping_acceleration_threshold = value; }
        }
        public bool ShouldSerializeclaping_acceleration_threshold()
        {
            return __pbn__claping_acceleration_threshold != null;
        }
        public void Resetclaping_acceleration_threshold()
        {
            __pbn__claping_acceleration_threshold = null;
        }
        private double? __pbn__claping_acceleration_threshold;

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue(1)]
        public double claping_speed_threshold
        {
            get { return __pbn__claping_speed_threshold ?? 1; }
            set { __pbn__claping_speed_threshold = value; }
        }
        public bool ShouldSerializeclaping_speed_threshold()
        {
            return __pbn__claping_speed_threshold != null;
        }
        public void Resetclaping_speed_threshold()
        {
            __pbn__claping_speed_threshold = null;
        }
        private double? __pbn__claping_speed_threshold;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class MlfShapeFilterConfig : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public MlfShapeFilterConfig()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue(0.1)]
        public double bottom_points_ignore_threshold
        {
            get { return __pbn__bottom_points_ignore_threshold ?? 0.1; }
            set { __pbn__bottom_points_ignore_threshold = value; }
        }
        public bool ShouldSerializebottom_points_ignore_threshold()
        {
            return __pbn__bottom_points_ignore_threshold != null;
        }
        public void Resetbottom_points_ignore_threshold()
        {
            __pbn__bottom_points_ignore_threshold = null;
        }
        private double? __pbn__bottom_points_ignore_threshold;

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue(1.6)]
        public double top_points_ignore_threshold
        {
            get { return __pbn__top_points_ignore_threshold ?? 1.6; }
            set { __pbn__top_points_ignore_threshold = value; }
        }
        public bool ShouldSerializetop_points_ignore_threshold()
        {
            return __pbn__top_points_ignore_threshold != null;
        }
        public void Resettop_points_ignore_threshold()
        {
            __pbn__top_points_ignore_threshold = null;
        }
        private double? __pbn__top_points_ignore_threshold;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class MlfEngineConfig : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public MlfEngineConfig()
        {
            main_sensor = new global::System.Collections.Generic.List<string>();
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public global::System.Collections.Generic.List<string> main_sensor { get; private set; }

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue(true)]
        public bool use_histogram_for_match
        {
            get { return __pbn__use_histogram_for_match ?? true; }
            set { __pbn__use_histogram_for_match = value; }
        }
        public bool ShouldSerializeuse_histogram_for_match()
        {
            return __pbn__use_histogram_for_match != null;
        }
        public void Resetuse_histogram_for_match()
        {
            __pbn__use_histogram_for_match = null;
        }
        private bool? __pbn__use_histogram_for_match;

        [global::ProtoBuf.ProtoMember(3)]
        [global::System.ComponentModel.DefaultValue(10)]
        public uint histogram_bin_size
        {
            get { return __pbn__histogram_bin_size ?? 10; }
            set { __pbn__histogram_bin_size = value; }
        }
        public bool ShouldSerializehistogram_bin_size()
        {
            return __pbn__histogram_bin_size != null;
        }
        public void Resethistogram_bin_size()
        {
            __pbn__histogram_bin_size = null;
        }
        private uint? __pbn__histogram_bin_size;

        [global::ProtoBuf.ProtoMember(4)]
        [global::System.ComponentModel.DefaultValue(false)]
        public bool output_predict_objects
        {
            get { return __pbn__output_predict_objects ?? false; }
            set { __pbn__output_predict_objects = value; }
        }
        public bool ShouldSerializeoutput_predict_objects()
        {
            return __pbn__output_predict_objects != null;
        }
        public void Resetoutput_predict_objects()
        {
            __pbn__output_predict_objects = null;
        }
        private bool? __pbn__output_predict_objects;

        [global::ProtoBuf.ProtoMember(5)]
        [global::System.ComponentModel.DefaultValue(0.2)]
        public double reserved_invisible_time
        {
            get { return __pbn__reserved_invisible_time ?? 0.2; }
            set { __pbn__reserved_invisible_time = value; }
        }
        public bool ShouldSerializereserved_invisible_time()
        {
            return __pbn__reserved_invisible_time != null;
        }
        public void Resetreserved_invisible_time()
        {
            __pbn__reserved_invisible_time = null;
        }
        private double? __pbn__reserved_invisible_time;

        [global::ProtoBuf.ProtoMember(6)]
        [global::System.ComponentModel.DefaultValue(false)]
        public bool use_frame_timestamp
        {
            get { return __pbn__use_frame_timestamp ?? false; }
            set { __pbn__use_frame_timestamp = value; }
        }
        public bool ShouldSerializeuse_frame_timestamp()
        {
            return __pbn__use_frame_timestamp != null;
        }
        public void Resetuse_frame_timestamp()
        {
            __pbn__use_frame_timestamp = null;
        }
        private bool? __pbn__use_frame_timestamp;

    }

}

#pragma warning restore 0612, 1591, 3021
