// This file was generated by a tool; you should avoid making direct changes.
// Consider using 'partial classes' to extend these types
// Input: rtk_config.proto

#pragma warning disable 0612, 1591, 3021
namespace apollo.localization.rtk_config
{

    [global::ProtoBuf.ProtoContract()]
    public partial class Config : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public Config()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue("")]
        public string localization_topic
        {
            get { return __pbn__localization_topic ?? ""; }
            set { __pbn__localization_topic = value; }
        }
        public bool ShouldSerializelocalization_topic()
        {
            return __pbn__localization_topic != null;
        }
        public void Resetlocalization_topic()
        {
            __pbn__localization_topic = null;
        }
        private string __pbn__localization_topic;

        [global::ProtoBuf.ProtoMember(11)]
        [global::System.ComponentModel.DefaultValue("")]
        public string localization_status_topic
        {
            get { return __pbn__localization_status_topic ?? ""; }
            set { __pbn__localization_status_topic = value; }
        }
        public bool ShouldSerializelocalization_status_topic()
        {
            return __pbn__localization_status_topic != null;
        }
        public void Resetlocalization_status_topic()
        {
            __pbn__localization_status_topic = null;
        }
        private string __pbn__localization_status_topic;

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue("")]
        public string imu_topic
        {
            get { return __pbn__imu_topic ?? ""; }
            set { __pbn__imu_topic = value; }
        }
        public bool ShouldSerializeimu_topic()
        {
            return __pbn__imu_topic != null;
        }
        public void Resetimu_topic()
        {
            __pbn__imu_topic = null;
        }
        private string __pbn__imu_topic;

        [global::ProtoBuf.ProtoMember(3)]
        [global::System.ComponentModel.DefaultValue("")]
        public string gps_topic
        {
            get { return __pbn__gps_topic ?? ""; }
            set { __pbn__gps_topic = value; }
        }
        public bool ShouldSerializegps_topic()
        {
            return __pbn__gps_topic != null;
        }
        public void Resetgps_topic()
        {
            __pbn__gps_topic = null;
        }
        private string __pbn__gps_topic;

        [global::ProtoBuf.ProtoMember(12)]
        [global::System.ComponentModel.DefaultValue("")]
        public string gps_status_topic
        {
            get { return __pbn__gps_status_topic ?? ""; }
            set { __pbn__gps_status_topic = value; }
        }
        public bool ShouldSerializegps_status_topic()
        {
            return __pbn__gps_status_topic != null;
        }
        public void Resetgps_status_topic()
        {
            __pbn__gps_status_topic = null;
        }
        private string __pbn__gps_status_topic;

        [global::ProtoBuf.ProtoMember(4)]
        [global::System.ComponentModel.DefaultValue("")]
        public string broadcast_tf_frame_id
        {
            get { return __pbn__broadcast_tf_frame_id ?? ""; }
            set { __pbn__broadcast_tf_frame_id = value; }
        }
        public bool ShouldSerializebroadcast_tf_frame_id()
        {
            return __pbn__broadcast_tf_frame_id != null;
        }
        public void Resetbroadcast_tf_frame_id()
        {
            __pbn__broadcast_tf_frame_id = null;
        }
        private string __pbn__broadcast_tf_frame_id;

        [global::ProtoBuf.ProtoMember(5)]
        [global::System.ComponentModel.DefaultValue("")]
        public string broadcast_tf_child_frame_id
        {
            get { return __pbn__broadcast_tf_child_frame_id ?? ""; }
            set { __pbn__broadcast_tf_child_frame_id = value; }
        }
        public bool ShouldSerializebroadcast_tf_child_frame_id()
        {
            return __pbn__broadcast_tf_child_frame_id != null;
        }
        public void Resetbroadcast_tf_child_frame_id()
        {
            __pbn__broadcast_tf_child_frame_id = null;
        }
        private string __pbn__broadcast_tf_child_frame_id;

        [global::ProtoBuf.ProtoMember(6)]
        public int imu_list_max_size
        {
            get { return __pbn__imu_list_max_size.GetValueOrDefault(); }
            set { __pbn__imu_list_max_size = value; }
        }
        public bool ShouldSerializeimu_list_max_size()
        {
            return __pbn__imu_list_max_size != null;
        }
        public void Resetimu_list_max_size()
        {
            __pbn__imu_list_max_size = null;
        }
        private int? __pbn__imu_list_max_size;

        [global::ProtoBuf.ProtoMember(7)]
        public double gps_imu_time_diff_threshold
        {
            get { return __pbn__gps_imu_time_diff_threshold.GetValueOrDefault(); }
            set { __pbn__gps_imu_time_diff_threshold = value; }
        }
        public bool ShouldSerializegps_imu_time_diff_threshold()
        {
            return __pbn__gps_imu_time_diff_threshold != null;
        }
        public void Resetgps_imu_time_diff_threshold()
        {
            __pbn__gps_imu_time_diff_threshold = null;
        }
        private double? __pbn__gps_imu_time_diff_threshold;

        [global::ProtoBuf.ProtoMember(8)]
        public double map_offset_x
        {
            get { return __pbn__map_offset_x.GetValueOrDefault(); }
            set { __pbn__map_offset_x = value; }
        }
        public bool ShouldSerializemap_offset_x()
        {
            return __pbn__map_offset_x != null;
        }
        public void Resetmap_offset_x()
        {
            __pbn__map_offset_x = null;
        }
        private double? __pbn__map_offset_x;

        [global::ProtoBuf.ProtoMember(9)]
        public double map_offset_y
        {
            get { return __pbn__map_offset_y.GetValueOrDefault(); }
            set { __pbn__map_offset_y = value; }
        }
        public bool ShouldSerializemap_offset_y()
        {
            return __pbn__map_offset_y != null;
        }
        public void Resetmap_offset_y()
        {
            __pbn__map_offset_y = null;
        }
        private double? __pbn__map_offset_y;

        [global::ProtoBuf.ProtoMember(10)]
        public double map_offset_z
        {
            get { return __pbn__map_offset_z.GetValueOrDefault(); }
            set { __pbn__map_offset_z = value; }
        }
        public bool ShouldSerializemap_offset_z()
        {
            return __pbn__map_offset_z != null;
        }
        public void Resetmap_offset_z()
        {
            __pbn__map_offset_z = null;
        }
        private double? __pbn__map_offset_z;

    }

}

#pragma warning restore 0612, 1591, 3021
