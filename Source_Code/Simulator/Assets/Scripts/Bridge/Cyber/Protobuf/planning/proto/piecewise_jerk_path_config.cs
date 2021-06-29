// This file was generated by a tool; you should avoid making direct changes.
// Consider using 'partial classes' to extend these types
// Input: piecewise_jerk_path_config.proto

#pragma warning disable 0612, 1591, 3021
namespace apollo.planning
{

    [global::ProtoBuf.ProtoContract()]
    public partial class PiecewiseJerkPathConfig : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public PiecewiseJerkPathConfig()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public PiecewiseJerkPathWeights default_path_config { get; set; }

        [global::ProtoBuf.ProtoMember(2)]
        public PiecewiseJerkPathWeights lane_change_path_config { get; set; }

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class PiecewiseJerkPathWeights : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public PiecewiseJerkPathWeights()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue(1)]
        public double l_weight
        {
            get { return __pbn__l_weight ?? 1; }
            set { __pbn__l_weight = value; }
        }
        public bool ShouldSerializel_weight()
        {
            return __pbn__l_weight != null;
        }
        public void Resetl_weight()
        {
            __pbn__l_weight = null;
        }
        private double? __pbn__l_weight;

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue(100)]
        public double dl_weight
        {
            get { return __pbn__dl_weight ?? 100; }
            set { __pbn__dl_weight = value; }
        }
        public bool ShouldSerializedl_weight()
        {
            return __pbn__dl_weight != null;
        }
        public void Resetdl_weight()
        {
            __pbn__dl_weight = null;
        }
        private double? __pbn__dl_weight;

        [global::ProtoBuf.ProtoMember(3)]
        [global::System.ComponentModel.DefaultValue(1000)]
        public double ddl_weight
        {
            get { return __pbn__ddl_weight ?? 1000; }
            set { __pbn__ddl_weight = value; }
        }
        public bool ShouldSerializeddl_weight()
        {
            return __pbn__ddl_weight != null;
        }
        public void Resetddl_weight()
        {
            __pbn__ddl_weight = null;
        }
        private double? __pbn__ddl_weight;

        [global::ProtoBuf.ProtoMember(4)]
        [global::System.ComponentModel.DefaultValue(10000)]
        public double dddl_weight
        {
            get { return __pbn__dddl_weight ?? 10000; }
            set { __pbn__dddl_weight = value; }
        }
        public bool ShouldSerializedddl_weight()
        {
            return __pbn__dddl_weight != null;
        }
        public void Resetdddl_weight()
        {
            __pbn__dddl_weight = null;
        }
        private double? __pbn__dddl_weight;

    }

}

#pragma warning restore 0612, 1591, 3021
