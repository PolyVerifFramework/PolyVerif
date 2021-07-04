// This file was generated by a tool; you should avoid making direct changes.
// Consider using 'partial classes' to extend these types
// Input: prediction_point.proto

#pragma warning disable 0612, 1591, 3021
namespace apollo.prediction
{

    [global::ProtoBuf.ProtoContract()]
    public partial class PredictionPathPoint : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public PredictionPathPoint()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1, IsRequired = true)]
        public double x { get; set; }

        [global::ProtoBuf.ProtoMember(2, IsRequired = true)]
        public double y { get; set; }

        [global::ProtoBuf.ProtoMember(3)]
        public double velocity_heading
        {
            get { return __pbn__velocity_heading.GetValueOrDefault(); }
            set { __pbn__velocity_heading = value; }
        }
        public bool ShouldSerializevelocity_heading()
        {
            return __pbn__velocity_heading != null;
        }
        public void Resetvelocity_heading()
        {
            __pbn__velocity_heading = null;
        }
        private double? __pbn__velocity_heading;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class PredictionTrajectoryPoint : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public PredictionTrajectoryPoint()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1, IsRequired = true)]
        public PredictionPathPoint path_point { get; set; }

        [global::ProtoBuf.ProtoMember(2, IsRequired = true)]
        public double timestamp { get; set; }

    }

}

#pragma warning restore 0612, 1591, 3021