// This file was generated by a tool; you should avoid making direct changes.
// Consider using 'partial classes' to extend these types
// Input: lattice_sampling_config.proto

#pragma warning disable 0612, 1591, 3021
namespace apollo.planning
{

    [global::ProtoBuf.ProtoContract()]
    public partial class LonCondition : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public LonCondition()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue(0)]
        public double s
        {
            get { return __pbn__s ?? 0; }
            set { __pbn__s = value; }
        }
        public bool ShouldSerializes()
        {
            return __pbn__s != null;
        }
        public void Resets()
        {
            __pbn__s = null;
        }
        private double? __pbn__s;

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue(0)]
        public double ds
        {
            get { return __pbn__ds ?? 0; }
            set { __pbn__ds = value; }
        }
        public bool ShouldSerializeds()
        {
            return __pbn__ds != null;
        }
        public void Resetds()
        {
            __pbn__ds = null;
        }
        private double? __pbn__ds;

        [global::ProtoBuf.ProtoMember(3)]
        [global::System.ComponentModel.DefaultValue(0)]
        public double dds
        {
            get { return __pbn__dds ?? 0; }
            set { __pbn__dds = value; }
        }
        public bool ShouldSerializedds()
        {
            return __pbn__dds != null;
        }
        public void Resetdds()
        {
            __pbn__dds = null;
        }
        private double? __pbn__dds;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class LatCondition : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public LatCondition()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue(0)]
        public double l
        {
            get { return __pbn__l ?? 0; }
            set { __pbn__l = value; }
        }
        public bool ShouldSerializel()
        {
            return __pbn__l != null;
        }
        public void Resetl()
        {
            __pbn__l = null;
        }
        private double? __pbn__l;

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue(0)]
        public double dl
        {
            get { return __pbn__dl ?? 0; }
            set { __pbn__dl = value; }
        }
        public bool ShouldSerializedl()
        {
            return __pbn__dl != null;
        }
        public void Resetdl()
        {
            __pbn__dl = null;
        }
        private double? __pbn__dl;

        [global::ProtoBuf.ProtoMember(3)]
        [global::System.ComponentModel.DefaultValue(0)]
        public double ddl
        {
            get { return __pbn__ddl ?? 0; }
            set { __pbn__ddl = value; }
        }
        public bool ShouldSerializeddl()
        {
            return __pbn__ddl != null;
        }
        public void Resetddl()
        {
            __pbn__ddl = null;
        }
        private double? __pbn__ddl;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class TStrategy : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public TStrategy()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public double[] t_markers { get; set; }

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue(0.5)]
        public double t_step
        {
            get { return __pbn__t_step ?? 0.5; }
            set { __pbn__t_step = value; }
        }
        public bool ShouldSerializet_step()
        {
            return __pbn__t_step != null;
        }
        public void Resett_step()
        {
            __pbn__t_step = null;
        }
        private double? __pbn__t_step;

        [global::ProtoBuf.ProtoMember(3)]
        [global::System.ComponentModel.DefaultValue("")]
        public string strategy
        {
            get { return __pbn__strategy ?? ""; }
            set { __pbn__strategy = value; }
        }
        public bool ShouldSerializestrategy()
        {
            return __pbn__strategy != null;
        }
        public void Resetstrategy()
        {
            __pbn__strategy = null;
        }
        private string __pbn__strategy;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class SStrategy : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public SStrategy()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public double[] s_markers { get; set; }

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue(0.5)]
        public double s_step
        {
            get { return __pbn__s_step ?? 0.5; }
            set { __pbn__s_step = value; }
        }
        public bool ShouldSerializes_step()
        {
            return __pbn__s_step != null;
        }
        public void Resets_step()
        {
            __pbn__s_step = null;
        }
        private double? __pbn__s_step;

        [global::ProtoBuf.ProtoMember(3)]
        [global::System.ComponentModel.DefaultValue("")]
        public string strategy
        {
            get { return __pbn__strategy ?? ""; }
            set { __pbn__strategy = value; }
        }
        public bool ShouldSerializestrategy()
        {
            return __pbn__strategy != null;
        }
        public void Resetstrategy()
        {
            __pbn__strategy = null;
        }
        private string __pbn__strategy;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class LonSampleConfig : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public LonSampleConfig()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public LonCondition lon_end_condition { get; set; }

        [global::ProtoBuf.ProtoMember(2)]
        public TStrategy t_strategy { get; set; }

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class LatSampleConfig : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public LatSampleConfig()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public LatCondition lat_end_condition { get; set; }

        [global::ProtoBuf.ProtoMember(2)]
        public SStrategy s_strategy { get; set; }

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class LatticeSamplingConfig : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public LatticeSamplingConfig()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public LonSampleConfig lon_sample_config { get; set; }

        [global::ProtoBuf.ProtoMember(2)]
        public LatSampleConfig lat_sample_config { get; set; }

    }

}

#pragma warning restore 0612, 1591, 3021
