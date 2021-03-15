// This file was generated by a tool; you should avoid making direct changes.
// Consider using 'partial classes' to extend these types
// Input: lon_controller_conf.proto

#pragma warning disable 0612, 1591, 3021
namespace apollo.control
{

    [global::ProtoBuf.ProtoContract()]
    public partial class FilterConf : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public FilterConf()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public int cutoff_freq
        {
            get { return __pbn__cutoff_freq.GetValueOrDefault(); }
            set { __pbn__cutoff_freq = value; }
        }
        public bool ShouldSerializecutoff_freq()
        {
            return __pbn__cutoff_freq != null;
        }
        public void Resetcutoff_freq()
        {
            __pbn__cutoff_freq = null;
        }
        private int? __pbn__cutoff_freq;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class LonControllerConf : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public LonControllerConf()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public double ts
        {
            get { return __pbn__ts.GetValueOrDefault(); }
            set { __pbn__ts = value; }
        }
        public bool ShouldSerializets()
        {
            return __pbn__ts != null;
        }
        public void Resetts()
        {
            __pbn__ts = null;
        }
        private double? __pbn__ts;

        [global::ProtoBuf.ProtoMember(2)]
        public double brake_minimum_action
        {
            get { return __pbn__brake_minimum_action.GetValueOrDefault(); }
            set { __pbn__brake_minimum_action = value; }
        }
        public bool ShouldSerializebrake_minimum_action()
        {
            return __pbn__brake_minimum_action != null;
        }
        public void Resetbrake_minimum_action()
        {
            __pbn__brake_minimum_action = null;
        }
        private double? __pbn__brake_minimum_action;

        [global::ProtoBuf.ProtoMember(3)]
        public double throttle_minimum_action
        {
            get { return __pbn__throttle_minimum_action.GetValueOrDefault(); }
            set { __pbn__throttle_minimum_action = value; }
        }
        public bool ShouldSerializethrottle_minimum_action()
        {
            return __pbn__throttle_minimum_action != null;
        }
        public void Resetthrottle_minimum_action()
        {
            __pbn__throttle_minimum_action = null;
        }
        private double? __pbn__throttle_minimum_action;

        [global::ProtoBuf.ProtoMember(4)]
        public double speed_controller_input_limit
        {
            get { return __pbn__speed_controller_input_limit.GetValueOrDefault(); }
            set { __pbn__speed_controller_input_limit = value; }
        }
        public bool ShouldSerializespeed_controller_input_limit()
        {
            return __pbn__speed_controller_input_limit != null;
        }
        public void Resetspeed_controller_input_limit()
        {
            __pbn__speed_controller_input_limit = null;
        }
        private double? __pbn__speed_controller_input_limit;

        [global::ProtoBuf.ProtoMember(5)]
        public double station_error_limit
        {
            get { return __pbn__station_error_limit.GetValueOrDefault(); }
            set { __pbn__station_error_limit = value; }
        }
        public bool ShouldSerializestation_error_limit()
        {
            return __pbn__station_error_limit != null;
        }
        public void Resetstation_error_limit()
        {
            __pbn__station_error_limit = null;
        }
        private double? __pbn__station_error_limit;

        [global::ProtoBuf.ProtoMember(6)]
        public double preview_window
        {
            get { return __pbn__preview_window.GetValueOrDefault(); }
            set { __pbn__preview_window = value; }
        }
        public bool ShouldSerializepreview_window()
        {
            return __pbn__preview_window != null;
        }
        public void Resetpreview_window()
        {
            __pbn__preview_window = null;
        }
        private double? __pbn__preview_window;

        [global::ProtoBuf.ProtoMember(7)]
        public double standstill_acceleration
        {
            get { return __pbn__standstill_acceleration.GetValueOrDefault(); }
            set { __pbn__standstill_acceleration = value; }
        }
        public bool ShouldSerializestandstill_acceleration()
        {
            return __pbn__standstill_acceleration != null;
        }
        public void Resetstandstill_acceleration()
        {
            __pbn__standstill_acceleration = null;
        }
        private double? __pbn__standstill_acceleration;

        [global::ProtoBuf.ProtoMember(8)]
        public PidConf station_pid_conf { get; set; }

        [global::ProtoBuf.ProtoMember(9)]
        public PidConf low_speed_pid_conf { get; set; }

        [global::ProtoBuf.ProtoMember(10)]
        public PidConf high_speed_pid_conf { get; set; }

        [global::ProtoBuf.ProtoMember(11)]
        public double switch_speed
        {
            get { return __pbn__switch_speed.GetValueOrDefault(); }
            set { __pbn__switch_speed = value; }
        }
        public bool ShouldSerializeswitch_speed()
        {
            return __pbn__switch_speed != null;
        }
        public void Resetswitch_speed()
        {
            __pbn__switch_speed = null;
        }
        private double? __pbn__switch_speed;

        [global::ProtoBuf.ProtoMember(12)]
        public PidConf reverse_station_pid_conf { get; set; }

        [global::ProtoBuf.ProtoMember(13)]
        public PidConf reverse_speed_pid_conf { get; set; }

        [global::ProtoBuf.ProtoMember(14)]
        public FilterConf pitch_angle_filter_conf { get; set; }

        [global::ProtoBuf.ProtoMember(15)]
        public LeadlagConf reverse_station_leadlag_conf { get; set; }

        [global::ProtoBuf.ProtoMember(16)]
        public LeadlagConf reverse_speed_leadlag_conf { get; set; }

        [global::ProtoBuf.ProtoMember(17)]
        public global::apollo.control.calibrationtable.ControlCalibrationTable calibration_table { get; set; }

        [global::ProtoBuf.ProtoMember(18)]
        [global::System.ComponentModel.DefaultValue(false)]
        public bool enable_reverse_leadlag_compensation
        {
            get { return __pbn__enable_reverse_leadlag_compensation ?? false; }
            set { __pbn__enable_reverse_leadlag_compensation = value; }
        }
        public bool ShouldSerializeenable_reverse_leadlag_compensation()
        {
            return __pbn__enable_reverse_leadlag_compensation != null;
        }
        public void Resetenable_reverse_leadlag_compensation()
        {
            __pbn__enable_reverse_leadlag_compensation = null;
        }
        private bool? __pbn__enable_reverse_leadlag_compensation;

    }

}

#pragma warning restore 0612, 1591, 3021
